"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2

def bake_time_remaining(elapsed_bake_time: int):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - elapsed_bake_time

def preparation_time_in_minutes(number_of_layers: int):
    """Calculate the preparation time.

    :param number_of_layers: int - number of layers in the lasagna.
    :return: int - time required to prepare the lasagna in minutes.

    Function that takes the number of layers added to the lasagna and returns
    how many minutes it will take to prepare it based on the `PREPARATION_TIME`.
    """

    return PREPARATION_TIME * number_of_layers


def elapsed_time_in_minutes(number_of_layers: int, elapsed_bake_time: int):
    """Calculate the total elapsed time.

    :param number_of_layers: int - number of layers in the lasagna.
    :param elapsed_bake_time: int - minutes elapsed since the lasagna was put in the oven
    :return: int - total time elapsed in minutes.

    Function that takes the number of layers added to the lasagna and the elapsed
    bake time and returns the total number of minutes elapsed.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
