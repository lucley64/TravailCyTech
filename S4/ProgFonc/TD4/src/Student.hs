{-# OPTIONS_GHC -Wno-missing-export-lists #-}

module Student where

import User (User)

data Student = Student {stuUser :: User, year :: Int}
  deriving (Show, Ord, Eq)
