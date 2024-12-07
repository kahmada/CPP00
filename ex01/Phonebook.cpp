/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:45:42 by kahmada           #+#    #+#             */
/*   Updated: 2024/12/07 20:55:04 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int just_spaces(std::string s);
PhoneBook::PhoneBook()  {
    currentIndex = 0;
}

std::string    read_line(std::string str, std::string name)
{
    if (getline(std::cin, str).eof())
        exit(1);
    while (str.empty() || just_spaces(str))
    {
        std::cout << "Contact cannot have any empty field." << std::endl << name;
        if (getline(std::cin, str).eof())
            exit(1);
    }
    return (str);
}

void PhoneBook::addContact()
{
    if (currentIndex == 8)
        currentIndex = 0;
    contacts[currentIndex].setDetails();
    currentIndex++;
}

void PhoneBook::searchContacts()
{
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < 8; i++)
    {
            contacts[i].displaySummary(i);
    }
    std::cout << "Enter an index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    if (input.empty() || just_spaces(input))
    {
         std::cerr << "Invalid index!\n";
         return ;
    }
    if (input[0] < '0' || input[0] > '9' || input.length() > 1)
    {
        std::cerr << "Invalid index!\n";
        return;
    }
    int index = std::stoi(input);
    if (index < 0 || index >= 8 || contacts[index].isEmpty())
        std::cerr << "Invalid index!\n";
    else
        contacts[index].displayDetails();
}
