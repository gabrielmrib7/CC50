SELECT movies.title, ratings.rating FROM movies JOIN ratings ON ratings.movie_id = movies.id where movies.year = "2010" ORDER BY ratings.rating DESC, title ASC;