// Book.java
import java.util.ArrayList;
import java.util.List;

public class Book {
    private String bookId;
    private String authorName;
    private String bookName;
    private double price;
    private int edition;
    private boolean available;
    private static List<Book> bookList = new ArrayList<>();
    
    public Book(String bookId, String bookName, String authorName, double price, int edition) {
        this.bookId = bookId;
        this.bookName = bookName;
        this.authorName = authorName;
        this.price = price;
        this.edition = edition;
        this.available = true;
        System.out.println("Created object Book " + bookId + " " + bookName + " " + edition + " edition");
        bookList.add(this);
        System.out.println("Add " + bookId + " To Book StaticList");
    }
    
    public static List<Book> getBookList() {
        return bookList;
    }
    
    public String getBookId() { return bookId; }
    public String getAuthorName() { return authorName; }
    public String getBookName() { return bookName; }
    public double getPrice() { return price; }
    public boolean isAvailable() { return available; }
    public void setAvailable(boolean available) { this.available = available; }
}

// Member.java
public abstract class Member {
    protected String name;
    protected String memberId;
    protected String phoneNumber;
    protected int maxBorrowBooks;
    protected int maxBorrowDays;
    protected List<Book> borrowedBooks;
    
    public Member(String name, String memberId, String phoneNumber) {
        this.name = name;
        this.memberId = memberId;
        this.phoneNumber = phoneNumber;
        this.borrowedBooks = new ArrayList<>();
        System.out.println("Created object Member " + memberId);
    }
    
    public String getMemberId() { return memberId; }
    public List<Book> getBorrowedBooks() { return borrowedBooks; }
    public int getMaxBorrowBooks() { return maxBorrowBooks; }
    public int getMaxBorrowDays() { return maxBorrowDays; }
    
    public abstract double calculateFine(int daysOverdue, Book book);
}

// Student.java
public class Student extends Member {
    private String studentId;
    private String faculty;
    
    public Student(String name, String memberId, String phoneNumber, String studentId, String faculty) {
        super(name, memberId, phoneNumber);
        this.studentId = studentId;
        this.faculty = faculty;
        this.maxBorrowBooks = 1;
        this.maxBorrowDays = 3;
    }
    
    @Override
    public double calculateFine(int daysOverdue, Book book) {
        return daysOverdue * 1.0; // 1 บาทต่อวัน
    }
}

// Lecturer.java
public class Lecturer extends Member {
    private String lecturerId;
    
    public Lecturer(String name, String memberId, String phoneNumber, String lecturerId) {
        super(name, memberId, phoneNumber);
        this.lecturerId = lecturerId;
        this.maxBorrowBooks = 3;
        this.maxBorrowDays = 5;
    }
    
    @Override
    public double calculateFine(int daysOverdue, Book book) {
        return daysOverdue * 0.5; // 0.5 บาทต่อวัน
    }
}

// General.java
public class General extends Member {
    private String address;
    private String citizenId;
    
    public General(String name, String memberId, String phoneNumber, String address, String citizenId) {
        super(name, memberId, phoneNumber);
        this.address = address;
        this.citizenId = citizenId;
        this.maxBorrowBooks = 3;
        this.maxBorrowDays = 5;
    }
    
    @Override
    public double calculateFine(int daysOverdue, Book book) {
        return daysOverdue * (book.getPrice() * 0.01); // 1% ของราคาหนังสือต่อวัน
    }
}

// Librarian.java
public class Librarian {
    private String name;
    private String librarianId;
    
    public Librarian(String name, String librarianId) {
        this.name = name;
        this.librarianId = librarianId;
        System.out.println("Created object Librarian " + librarianId);
    }
    
    public String getName() { return name; }
    public String getLibrarianId() { return librarianId; }
    
    public void checkBooksByAuthor(String authorName) {
        System.out.println("Librarian " + librarianId + " Check Book Author");
        for (Book book : Book.getBookList()) {
            if (book.getAuthorName().equals(authorName)) {
                System.out.println(book.getBookId() + " " + book.getBookName());
            }
        }
    }
    
    public void checkAllBookStatus() {
        System.out.println("Librarian " + librarianId + " Check Book Status");
        for (Book book : Book.getBookList()) {
            System.out.println(book.getBookId() + " " + (book.isAvailable() ? "available" : "unavailable"));
        }
    }
}

// BorrowBook.java
import java.util.ArrayList;
import java.util.List;

public class BorrowBook {
    private Member member;
    private Book book;
    private String borrowDate;
    private String returnDate;
    private Librarian borrowLibrarian;
    private Librarian returnLibrarian;
    private static List<BorrowBook> borrowList = new ArrayList<>();
    
    public BorrowBook(Member member, Book book, String borrowDate, Librarian librarian) {
        this.member = member;
        this.book = book;
        this.borrowDate = borrowDate;
        this.borrowLibrarian = librarian;
        System.out.println("Created object Borrow");
        borrowList.add(this);
        System.out.println("Add obj Borrow StaticList");
    }
    
    public static List<BorrowBook> getBorrowList() {
        return borrowList;
    }
    
    public Member getMember() { return member; }
    public Book getBook() { return book; }
    public String getBorrowDate() { return borrowDate; }
    public void setReturnDate(String returnDate) { this.returnDate = returnDate; }
    public void setReturnLibrarian(Librarian librarian) { this.returnLibrarian = librarian; }
}

// TestBook.java
public class TestBook {
    public static void borrowBook(Member member, Book book, String date, Librarian librarian) {
        System.out.print(member.getMemberId() + " borrow " + book.getBookId() + 
                        " Librarian " + date + " " + librarian.getLibrarianId() + 
                        " << " + librarian.getName() + ">> ");
        
        if (!book.isAvailable()) {
            System.out.println("Denied <<Book is unavailable>>");
            return;
        }
        
        if (member.getBorrowedBooks().size() >= member.getMaxBorrowBooks()) {
            System.out.println("Denied <<Borrow too much>>");
            return;
        }
        
        book.setAvailable(false);
        member.getBorrowedBooks().add(book);
        new BorrowBook(member, book, date, librarian);
        System.out.println("<<OK>> add book toList borrow");
    }
    
    public static void returnBook(Member member, Book book, String date, Librarian librarian) {
        System.out.print(member.getMemberId() + " return " + book.getBookId() + " " + 
                        date + " Librarian " + librarian.getLibrarianId() + 
                        " << " + librarian.getName() + ">> ");
        
        // Find the borrow record
        BorrowBook borrowRecord = null;
        for (BorrowBook record : BorrowBook.getBorrowList()) {
            if (record.getMember() == member && record.getBook() == book) {
                borrowRecord = record;
                break;
            }
        }
        
        if (borrowRecord == null) {
            System.out.println("Error: No borrow record found");
            return;
        }
        
        // Calculate days and fine
        int daysOverdue = calculateDaysOverdue(borrowRecord.getBorrowDate(), date);
        if (daysOverdue > member.getMaxBorrowDays()) {
            double fine = member.calculateFine(daysOverdue - member.getMaxBorrowDays(), book);
            System.out.println("<<fine>> " + fine + " No Book");
        } else {
            System.out.println("<<OK>> No Book");
        }
        
        book.setAvailable(true);
        member.getBorrowedBooks().remove(book);
        borrowRecord.setReturnDate(date);
        borrowRecord.setReturnLibrarian(librarian);
    }
    
    private static int calculateDaysOverdue(String borrowDate, String returnDate) {
        // Simple implementation - assuming dates are in format "dd / mm / yyyy"
        // In real implementation, should use proper date parsing and calculation
        return 5; // Dummy implementation for demonstration
    }
    
    public static void main(String[] args) {
        // Create books
        Book b1 = new Book("B-001", "Harry Potter and the Philosopher's Stone", "J.K. Rowling", 320, 1);
        Book b2 = new Book("B-002", "Harry Potter and the Chamber of Secrets", "J.K. Rowling", 350, 1);
        Book b3 = new Book("B-003", "Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", 400, 3);
        Book b4 = new Book("B-004", "The Ice Monster", "David Walliams", 250, 1);
        Book b5 = new Book("B-005", "The Wizards of Once: Book 1", "David Walliams", 250, 1);
        Book b6 = new Book("B-006", "Harry Potter and the Philosopher's Stone", "J.K. Rowling", 330, 2);

        // Create members
        Lecturer memberA = new Lecturer("A", "M-001", "091-944-5445", "E0145");
        Student memberB = new Student("B", "M-002", "091-044-1441", "61014140", "Engineering");
        General memberC = new General("C", "M-003", "095-189-4696", "14/5 Kamphaeng saen Nakhon Patom", "125-74-28431-854");

        // Create librarians
        Librarian libra = new Librarian("Libra", "L-001");
        Librarian pibra = new Librarian("PIbra", "L-002");

        // Check books by author
        libra.checkBooksByAuthor("J.K. Rowling");

        // Perform borrows
        borrowBook(memberA, b1, "1/12/2561", libra);
        borrowBook(memberA, b2, "1/12/2561", libra);
        borrowBook(memberA, b3, "1/12/2561", libra);
        borrowBook(memberA, b4, "1/12/2561", libra);
        borrowBook(memberB, b2, "2/12/2561", pibra);
        
        // Check book status
        System.out.println("Member " + memberB.getMemberId() + " Check Book Status");
        for (Book book : Book.getBookList()) {
            System.out.println(book.getBookId() + " " + (book.isAvailable() ? "available" : "unavailable"));
        }

        // More borrows
        borrowBook(memberB, b4, "2/12/2561", pibra);
        borrowBook(memberB, b1, "2/12/2561", pibra);
        borrowBook(memberC, b6, "2/12/2561", libra);

        // Returns
        returnBook(memberA, b1, "3/12/2561", pibra);
        pibra.checkAllBookStatus();
        returnBook(memberA, b2, "5/12/2561", libra);
        returnBook(memberA, b3, "10/12/2561", libra);
        returnBook(memberB, b4, "8/12/2561", libra);
        returnBook(memberC, b6, "12/12/2561", pibra);
    }
}
