module Main where

import Data.Char (digitToInt)

twoToN :: Int -> Integer
twoToN n = product $ replicate n 2

main :: IO ()
main = putStrLn
  $ show
  $ sum
  $ map digitToInt
  $ show
  $ twoToN 1000
