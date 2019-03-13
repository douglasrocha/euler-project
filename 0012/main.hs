{- We should get the first number with a divisors count
   greater or equal to 500.

   I solved this problem by applying a naive divisors count
   function. I could have used the function tau, but since
   it was more complex, the complexity of this algorithm
   O(n*sqrt(n)) solves it without problem.

   Another naive approach made by myself was to use the
   function nub, which uses a quadratic approach to find
   repetitions. I just wanted to use a simple Prelude
   function.
-}

module Main where

import Data.List (nub)

flatten :: [[a]] -> [a]
flatten xss = foldr (++) [] xss

cumulativeSum :: [Int]
cumulativeSum = scanl1 (+) [1..]

divisorsCount :: Int -> Int
divisorsCount n = length $ nub $ flatten $ map (getDiv n) [1 .. intSqrt]
  where getDiv x d = if x `mod` d == 0
                     then [d, x `div` d]
                     else [1, 1]
        intSqrt :: Int
        intSqrt = (floor . sqrt . fromIntegral) n

main :: IO ()
main = do
  putStrLn
    $ show
    $ head
    $ dropWhile (\x -> (snd x) < 500)
    $ map (\x -> (x, divisorsCount x))
    $ cumulativeSum
