# C++ Programs

## 1. Date Manipulation Program

This C++ program allows the user to work with two date objects (`date1` and `date2`) and perform operations like:

- **Set Date**: Input a valid day, month, and year considering leap years and month-day limits.
- **Print Date**: Display the current date in DD/MM/YYYY format.
- **Increment/Decrement Date**: Adjust the date by one day forward or backward.
- **Date Difference**: Calculate and display the difference between two dates in days.

### Key Features:
- Leap year check for February.
- Validation to ensure proper day/month entry.
- Simple arithmetic to calculate date differences.

```cpp
date1 p;
date2 q;
p.setDate();
q.setDate();
p.printDate();
q.printDate();
diff(p, q);
```

## 2. Array Manipulation Program

This C++ program is designed to handle basic operations on a static array of size 5, including:

- **Initialize Array**: Set all elements to zero.
- **Set Data**: Input values into the array.
- **Display Data**: Print the array values.
- **Calculate Total and Average**: Sum all elements and find their average.
- **Find Maximum/Minimum**: Get the largest and smallest elements.
- **Search and Replace**: Find an element and replace it.
- **Check if Ordered**: Determine if the array is sorted in non-decreasing order.

### Menu Options:
1. Enter new data.
2. Display the array.
3. Calculate total and average of elements.
4. Find and replace a specific value.
5. Check if the array is ordered.

```cpp
Array d;
d.setdata();
d.display();
cout << d.caltot();
```

## 3. Account Management System

This C++ program simulates a simple bank account management system, allowing operations on account records stored in a binary file (`Acc.DAT`). Key operations include:

- **Add Account**: Create a new account with account number, name, and initial balance.
- **Modify Account**: Update details of an existing account.
- **Delete Account**: Mark an account as inactive.
- **Display All Accounts**: Show all account records, including inactive ones.

### Features:
- **File handling with `fstream`** for permanent storage.
- **Search for accounts by number**.
- **Menu-driven interface** for easy interaction.

```cpp
AccAMD a;
a.menu();
```
