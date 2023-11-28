#!/bin/bash

MAX_RECORDS=100
echo "Samarth Khorate SE AIDS A2 [22539]"

declare -a addressBook
count=0

createAddressBook() {
    addressBook=()
    count=0
    echo "Address book created."
}

viewAddressBook() {
    if [ $count -eq 0 ]; then
        echo "Address book is empty."
    else
        echo -e "\nAddress Book:"
        for ((i = 0; i < count; i++)); do
            echo "Record $((i + 1)):"
            echo "Name: ${addressBook[i,name]}"
            echo "Address: ${addressBook[i,address]}"
            echo "Phone: ${addressBook[i,phone]}"
            echo
        done
    fi
}

insertRecord() {
    if [ $count -lt $MAX_RECORDS ]; then
        read -p "Enter Name: " name
        read -p "Enter Address: " address
        read -p "Enter Phone: " phone

        addressBook+=([name]="$name" [address]="$address" [phone]="$phone")

        echo "Record added successfully."
        ((count++))
    else
        echo "Address book is full. Cannot add more records."
    fi
}

deleteRecord() {
    if [ $count -gt 0 ]; then
        read -p "Enter the index of the record to delete (1 to $count): " index

        if ((index >= 1 && index <= count)); then
            unset 'addressBook[index-1]'
            addressBook=("${addressBook[@]}")

            ((count--))
            echo "Record deleted successfully."
        else
            echo "Invalid index. Please enter a valid index."
        fi
    else
        echo "Address book is empty. Cannot delete a record."
    fi
}

modifyRecord() {
    if [ $count -gt 0 ]; then
        read -p "Enter the index of the record to modify (1 to $count): " index

        if ((index >= 1 && index <= count)); then
            read -p "Enter new Name: " name
            read -p "Enter new Address: " address
            read -p "Enter new Phone: " phone

            addressBook[index-1]=([name]="$name" [address]="$address" [phone]="$phone")

            echo "Record modified successfully."
        else
            echo "Invalid index. Please enter a valid index."
        fi
    else
        echo "Address book is empty. Cannot modify a record."
    fi
}

echo "Address Book Program"

while true; do
    echo -e "\nOptions:"
    echo "a) Create address book"
    echo "b) View address book"
    echo "c) Insert a record"
    echo "d) Delete a record"
    echo "e) Modify a record"
    echo "f) Exit"
    read -p "Enter your choice: " choice

    case $choice in
    "a")
        createAddressBook
        ;;
    "b")
        viewAddressBook
        ;;
    "c")
        insertRecord
        ;;
    "d")
        deleteRecord
        ;;
    "e")
        modifyRecord
        ;;
    "f")
        echo "Exiting the program. Goodbye!"
        exit 0
        ;;
    *)
        echo "Invalid choice. Please enter a valid option."
        ;;
    esac
done
