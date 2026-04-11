# Write your MySQL query statement below
select Email from Person
group by Email
Having Count(Email) > 1;