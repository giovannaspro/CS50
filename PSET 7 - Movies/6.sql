-- write a SQL query to determine the average rating of all movies released in 2012
SELECT AVG(rating) FROM ratings 
INNER JOIN movies
    ON movies.id = ratings.movie_id
WHERE year = 2012;