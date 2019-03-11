module Main where

fibo :: [Int]
fibo = 0 : 1 : zipWith (+) fibo (tail fibo)

main = do
  putStrLn
    $ show
    $ sum
    $ filter even
    $ takeWhile (<4000000) fibo
