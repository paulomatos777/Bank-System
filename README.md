# Bank-System

A C program that implements a banking system. The program
contains:

i. Instructions that read bank details of multiple customers into one file
called “CLIENTS.txt” . These data include
account number (int), customer name (string) and surname (string), and balance (float).

ii. Instructions that read various banking transactions present in a file
called “TRANSACTIONS.txt”. The data in this file includes number
of account, transaction type (char - positive = cash inflow,
negative = outflow of money), and (3) transaction amount (float);

iii. Instructions that calculate the new balance of customers after performing the
transactions contained in “TRANSACTIONS.txt”.

iv. Instructions to save customers in a “DEVEDORES.txt” file only
with negative balance. The information contained in this file must include
account number, customer name and surname (String) and balance
current;

v. A CustomerData struct is used to store information about customers and
fread() and fwrite() to read/write files;





# Sistema-Bancário

UM programa em C que implementa um sistema bancário. O programa
contem :

i. Instruções que leiam dados bancários de vários clientes em um arquivo
chamado “CLIENTES.txt” . Estes dados incluem 
número da conta (int), nome (string) e sobrenome (string) do cliente, e saldo (float).

ii. Instruções que leiam diversas transações bancárias presentes em um arquivo
chamado “TRANSACTIONS.txt”. Os dados deste arquivo incluem número
da conta , tipo da transação (char – positiva = entrada de dinheiro,
negativa = saída de dinheiro), e (3) valor da transação (float);

iii. Instruções que calculem o novo saldo dos clientes após realizarem as
transações contidas em “TRANSACTIONS.txt”.

iv. Instruções para salvar em um arquivo “DEVEDORES.txt” apenas os clientes
com saldo negativo. As informações contidas neste arquivo devem incluir 
número da conta , nome e sobrenome do cliente (String) e saldo
atual;

v.É utilizado uma struct dadosClientes para guardar informações sobre clientes e
fread() e fwrite() para ler/escrever arquivos;
