module Classroom (Classroom, clssrmName, clssrmBuilding, clssrmCapacity) where

data Classroom = Classroom {clssrmName :: String, clssrmBuilding :: String, clssrmCapacity :: Int}
  deriving (Show, Eq)