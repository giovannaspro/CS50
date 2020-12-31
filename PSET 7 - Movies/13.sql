-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT name 
FROM movies INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE movie_id IN
(SELECT movie_id
FROM people INNER JOIN stars ON people.id = stars.person_id
WHERE name LIKE "%Kevin Bacon%" AND birth = 1958)
AND name NOT LIKE "%Kevin Bacon%";