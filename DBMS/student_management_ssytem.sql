CREATE DATABASE SchoolManagementSystem; --creates a database

USE SchoolManagementSystem; --makes ready to write inside this database

--creates students tables and writes variables
CREATE TABLE Student (
    Std_id INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(50),
    Address VARCHAR(100),
    Email VARCHAR(100)
);

--creates instructors tables
CREATE TABLE Instructor (
    Instructor_id INT PRIMARY KEY AUTO_INCREMENT,
    Instructor_Name VARCHAR(100),
    Address VARCHAR(100),
    Email VARCHAR(100)
);

--course_table
CREATE TABLE Course (
    Course_id INT PRIMARY KEY AUTO_INCREMENT,
    Course_Name VARCHAR(100),
    Credits INT CHECK(Credits > 0),
    Instructor_id INT,
    FOREIGN KEY (Instructor_id) REFERENCES Instructor(Instructor_id)
);

--enrollment table
CREATE TABLE Enrollment (
    Enrollment_id INT PRIMARY KEY AUTO_INCREMENT,
    Std_id INT,
    Course_id INT,
    Enrollment_Date DATE,
    FOREIGN KEY (Std_id) REFERENCES Student(Std_id),
    FOREIGN KEY (Course_id) REFERENCES Course(Course_id)
);

--inserts values into the student table
INSERT INTO Student (Name, Address, Email) VALUES
('Abishek Adhikari', 'Ranipauwa-Pokhara', 'adh.abishek@gmail.com'),
('Wagle Amrit', 'Bagar-Pokhara', 'amritwagle@gmail.com'),
('Bimal Gautam', 'Hemja Pokhara', 'gbinal2057@gmail.com');

--inserts int the instructor table
INSERT INTO Instructor (Instructor_Name, Address, Email) VALUES
('Abc Thapa', 'Syangja', 'abc@gmail.com'),
('Xyz Gurung', 'Pokhara', 'xyz@gmail.com'),
('Pqr Magar', 'Kathmandu', 'pqr@example.com');

--inserts into the course table
INSERT INTO Course (Course_Name, Credits, Instructor_id) VALUES
('Math', 3, 1),
('C++', 4, 2),
('DBMS', 3, 3);

--inserts into the enrollment table
INSERT INTO Enrollment (Std_id, Course_id, Enrollment_Date) VALUES
(1, 1, '2024-09-01'),
(2, 2, '2024-08-19'),
(3, 1, '2024-09-02');


--creates a view page by joining the necessary tables
CREATE OR REPLACE VIEW studentsCourseView AS 
SELECT 
    student.std_id, 
    student.name AS student_name, 
    student.email AS student_email, 
    course.course_id, 
    course.course_name, 
    course.credits, 
    instructor.instructor_name AS instructor_name, 
    instructor.email AS instructor_email, 
    enrollment.enrollment_date 
FROM enrollment 
JOIN student ON enrollment.std_id = student.std_id 
JOIN course ON enrollment.course_id = course.course_id 
JOIN instructor ON course.instructor_id = instructor.instructor_id;

--view all data from view created file
SELECT * FROM studentsCourseView;

--view all data from the tables 
SELECT * FROM student;
SELECT * FROM instructor;
SELECT * FROM course;
SELECT * FROM enrollment;

--filters those student whose id=1
SELECT * FROM student where std_id=1;

