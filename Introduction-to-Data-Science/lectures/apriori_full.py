# =============================================================
#  Apriori Algorithm - Market Basket Analysis
#  วิเคราะห์ความสัมพันธ์ของสินค้าที่ถูกซื้อร่วมกัน
# =============================================================

# ── 1. Import Libraries ──────────────────────────────────────
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# mlxtend คือ library สำหรับทำ Association Rule Mining
from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder


# ── 2. โหลดข้อมูล ────────────────────────────────────────────
# อ่านไฟล์ Excel ที่มีข้อมูลการซื้อสินค้า (แต่ละแถว = 1 บิล)
# header=None เพราะไม่มีชื่อคอลัมน์ในไฟล์
# ต้องติดตั้ง openpyxl ก่อน: pip install openpyxl
raw_data = pd.read_excel('./data/MarketBasketOptimization.xlsx', header=None)


# ── 3. แปลงข้อมูลเป็น List of Transactions ───────────────────
# สร้าง list โดยแต่ละ element คือรายการสินค้าในแต่ละบิล
# ตัด NaN ออก เพราะบางบิลซื้อสินค้าน้อยกว่าจำนวน column ทั้งหมด
dataset = []
for i in range(0, len(raw_data)):           # ลูปทุกแถว (ทุกบิล)
    tmp = []
    for j in range(0, len(raw_data.loc[i])): # ลูปทุก column ในแถวนั้น
        if raw_data.loc[i, j] is not np.nan:  # เอาเฉพาะที่ไม่ใช่ค่าว่าง
            tmp.append(raw_data.loc[i, j])
    dataset.append(tmp)

# ตรวจสอบ: ดูสินค้าในบิลที่ 4 (index 3)
print(dataset[3])  # output: ['turkey', 'avocado']


# ── 4. One-Hot Encoding ด้วย TransactionEncoder ──────────────
# แปลง list of transactions → matrix True/False
# True  = สินค้าถูกซื้อในบิลนั้น
# False = สินค้าไม่ถูกซื้อในบิลนั้น
TE = TransactionEncoder()
tmp_dataset = TE.fit_transform(dataset)  # shape: (7501 บิล, 120 สินค้า)

# แปลงเป็น DataFrame เพื่อให้ใช้งานง่ายขึ้น
# columns_ คือชื่อสินค้าทั้งหมดที่ TransactionEncoder เก็บไว้
df = pd.DataFrame(tmp_dataset, columns=TE.columns_)
print(df.head(2))


# ── 5. หา Frequent Itemsets ด้วย Apriori ─────────────────────
# apriori จะหากลุ่มสินค้าที่ถูกซื้อร่วมกันบ่อยพอตามเกณฑ์ min_support
#
# min_support = 0.01 หมายความว่า สินค้า/กลุ่มสินค้านั้น
#               ต้องปรากฏในอย่างน้อย 1% ของบิลทั้งหมด
#               (7501 บิล × 0.01 ≈ 75 บิล)
#
# use_colnames=True → แสดงชื่อสินค้าแทน index
#
# drop('mineral water') → ตัด mineral water ออกเพราะซื้อบ่อยมากเกินไป
#                          อาจทำให้ rule ที่ได้ไม่มีความหมาย
itemset = apriori(df.drop('mineral water', axis=1),
                  min_support=0.01,
                  use_colnames=True)
print(itemset)
# ผลลัพธ์: DataFrame มี 2 คอลัมน์
#   support  = สัดส่วนที่กลุ่มสินค้านี้ปรากฏในบิลทั้งหมด
#   itemsets = กลุ่มสินค้า (1 ชิ้น หรือหลายชิ้น)


# ── 6. สร้าง Association Rules ───────────────────────────────
# จาก frequent itemsets → สร้าง if-then rules
# เช่น: ถ้าซื้อ {eggs, spaghetti} → มักจะซื้อ {chocolate} ด้วย
#
# metric='confidence' → ใช้ confidence เป็นเกณฑ์กรอง rule
# min_threshold=0.25  → confidence ต้องมากกว่า 25%
#
# ความหมายของ metric แต่ละตัวในผลลัพธ์:
#   antecedents        = สินค้าฝั่ง "ถ้า..." (IF)
#   consequents        = สินค้าฝั่ง "แล้ว..." (THEN)
#   antecedent support = ความถี่ของฝั่ง antecedents
#   consequent support = ความถี่ของฝั่ง consequents
#   support            = ความถี่ที่ทั้งสองฝั่งปรากฏพร้อมกัน
#   confidence         = P(consequents | antecedents) — ความน่าเชื่อถือของ rule
#   lift               = confidence / consequent support
#                        > 1 = ซื้อร่วมกันมากกว่าที่คาด (rule น่าสนใจ)
#                        = 1 = ไม่มีความสัมพันธ์
#                        < 1 = ซื้อร่วมกันน้อยกว่าที่คาด
#   leverage           = support - (antecedent support × consequent support)
#   conviction         = ยิ่งมาก rule ยิ่งเชื่อถือได้ (∞ = สมบูรณ์แบบ)
rule = association_rules(itemset, metric='confidence', min_threshold=0.25)
print(rule)
