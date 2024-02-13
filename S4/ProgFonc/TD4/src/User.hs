{-# OPTIONS_GHC -Wno-missing-export-lists #-}

module User where

data User = User {usrName :: String, usrFirstname :: String, usrAge :: Int}
  deriving (Show, Ord, Eq)
