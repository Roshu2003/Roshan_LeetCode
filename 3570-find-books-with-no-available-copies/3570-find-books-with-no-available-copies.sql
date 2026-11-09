# Write your MySQL query statement below
SELECT 
    l.book_id, 
    l.title, 
    l.author, 
    l.genre, 
    l.publication_year, 
    l.total_copies AS current_borrowers
FROM library_books l
Join borrowing_records b
on l.book_id = b.book_id
where b.return_date is NUll
group by l.book_id
having count(*) = l.total_copies
order by current_borrowers desc, l.title;