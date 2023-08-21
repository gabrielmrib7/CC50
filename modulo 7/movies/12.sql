SELECT movies.title FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people on people.id = stars.person_id
WHERE people.name = "Johnny Depp" or people.name = "Helena Bonham Carter"
GROUP BY movies.title
HAVING COUNT(movies.title)>1;