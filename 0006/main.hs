module Main where

sumOfSquares :: Integer -> Integer
sumOfSquares n = sum $ map square [1..n] where
  square x = x * x

squareOfSums :: Integer -> Integer
squareOfSums n = (square . sum) [1..n] where
  square x = x * x

main = do
  let sqs = squareOfSums 100
  let ssq = sumOfSquares 100
  putStrLn $ show $ sqs - ssq
