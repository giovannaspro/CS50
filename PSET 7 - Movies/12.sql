-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
SELECT title 
FROM movies INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE name LIKE "%Johnny Depp%"

INTERSECT

SELECT title 
FROM movies INNER JOIN stars ON stars.movie_id = movies.id
INNER JOIN people ON people.id = stars.person_id
WHERE name LIKE "%Helena Bonham Carter%";