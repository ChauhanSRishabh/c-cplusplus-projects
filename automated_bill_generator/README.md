# AUTOMATED BILL GENERATOR

Suppose you have a template -> bill.txt. You have to fill this template with values.  

bill.txt looks like this : Thanks {{name}} for purchasing {{item}} from {{outlet}}. {{name}}, Please visit {{outlet}} in case you face any issues with your {{item}}. We hope to serve you again soon.

We have written a program that will automatically fill this template with the given values.

For this, we have to read this file and replace {{\<placeholders\>}} with the given values:  
- {{name}} - Rishabh  
- {{item}} - iPhone  
- {{outlet}} - Croma

## Functions Used

The important functions used are:
- FILE functions in C to read and write to files.
- strstr() : Read more about it, [here](https://www.geeksforgeeks.org/strstr-in-ccpp/)
- strcpy() : Read more about it, [here](https://www.geeksforgeeks.org/strcpy-in-c-cpp/)

## OUTPUT

<img width="1160" alt="Screenshot 2022-08-16 at 11 02 35 PM" src="https://user-images.githubusercontent.com/15028913/184942595-96f4245f-6278-4ff8-b267-517e4de666bf.png">