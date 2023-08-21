SELECT movies.title FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN ratings on movies.id = ratings.movie_id
JOIN people on people.id = stars.person_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;