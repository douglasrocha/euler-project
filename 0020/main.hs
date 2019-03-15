module Main where

import Data.Char (digitToInt)

main :: IO ()
main = do
  putStrLn
    $ show
    $ sum
    $ map digitToInt 
    $ show
    $ (product [1..100]::Integer)
