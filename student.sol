// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {

    // Structure to store student information
    struct Student {
        uint id;
        string name;
        uint age;
        string department;
    }

    // Array of students
    Student[] public students;

    // Add a new student
    function addStudent(
        uint _id,
        string memory _name,
        uint _age,
        string memory _department
    ) public {
        students.push(
            Student(_id, _name, _age, _department)
        );
    }

    // Get student data using array index
    function getStudent(uint _index)
        public
        view
        returns (
            uint,
            string memory,
            uint,
            string memory
        )
    {
        Student memory s = students[_index];

        return (
            s.id,
            s.name,
            s.age,
            s.department
        );
    }

    // Get total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }
}