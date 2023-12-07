# Operating-System-Project-Sweet-Harmony-
This is a operating system project. I build it using Linux Ubuntu operating system. 

Problem Statement:

Sweet Harmony.
In the small, picturesque town of Pastelville, there is a lovely bakery called &quot;Sweet Harmony.&quot;
This bakery is famous for its scrumptious pastries and charming atmosphere. The bakery has a
limited number of tables for customers to sit and enjoy their treats. To maintain the pleasant
ambiance, they have a unique rule: at any given time, there can only be an equal number of
customers wearing red and blue outfits inside the bakery.
Sweet Harmony&#39;s staff must manage the following aspects:
1. Allowing customers to enter the bakery while maintaining the equal number of red and
blue outfits rule.
2. Ensuring customers can find a table to sit at or wait for a table to become available.
3. Managing the queue of customers waiting outside the bakery when the equal outfit rule
cannot be maintained.
4. Handling customers leaving the bakery, freeing up tables, and allowing new customers to
enter.

A C program can be developed using semaphores, processes, and thread mutex locks to address
the above challenges:
1. Semaphores can be used to manage the equal outfit rule, allowing only customers with
matching outfits to enter.
2. Processes can represent individual customers and their actions (entering the bakery,
finding a table, waiting, and leaving).
3. Thread mutex locks can be used to synchronize the available tables, ensuring customers
can only sit at a free table.
4. Additional semaphores can be used to manage the waiting queue outside the bakery.
By utilizing semaphores, processes, and thread mutex locks, the C program can effectively
simulate the charming environment at Sweet Harmony bakery, while addressing the concurrency
issues and unique outfit rule that arise in this scenario.
