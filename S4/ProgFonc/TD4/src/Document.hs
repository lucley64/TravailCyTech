{-# OPTIONS_GHC -Wno-missing-export-lists #-}

module Document where

import TD4Exo (includes)

data Document = Document {title :: String, keywords :: [String]}
  deriving (Show)

searchByKeword :: String -> [Document] -> [Document]
searchByKeword kw = filter (elem kw . keywords)

searchByKewords :: [String] -> [Document] -> [Document]
searchByKewords kws = filter (\doc -> keywords doc `includes` kws)

relevance :: [String] -> Document -> Int
relevance kws doc = length (filter (\kw -> kw `elem` keywords doc) kws)
