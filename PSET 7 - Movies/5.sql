-- write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order
SELECT title, year FROM movies WHERE title LIKE "%harry potter%"
ORDER BY year ASC;