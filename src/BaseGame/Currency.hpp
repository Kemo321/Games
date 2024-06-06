#pragma once
#include <functional>

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @class Currency
 * @brief Represents a currency with a value.
 */
class Currency
{
    int _value; ///< The value of the currency.

public:
    /**
     * @brief Constructor to initialize a currency with a given initial value.
     * @param initial_value The initial value of the currency.
     */
    Currency(int initial_value = 0) : _value{ initial_value } {}

    /**
     * @brief Destructor.
     */
    ~Currency() = default;

    /**
     * @brief Gets the value of the currency.
     * @return The value of the currency.
     */
    int get_value() const;

    /**
     * @brief Sets the value of the currency.
     * @param new_value The new value of the currency.
     */
    void set_value(int new_value);

    /**
     * @brief Adds a value to the currency.
     * @param value_to_add The value to add to the currency.
     */
    void add_value(int value_to_add);

    /**
     * @brief Updates the value of the currency using a provided function.
     * @param func The function to update the value of the currency.
     */
    void update_value(std::function<int(int old_value)> func);
};
