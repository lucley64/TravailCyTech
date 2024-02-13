{-# OPTIONS_GHC -Wno-missing-export-lists #-}

module Teacher where

import User (User)

data Teacher = Teacher {tchrUser :: User, dep :: String, seniority :: Int}
  deriving (Show, Ord, Eq)
