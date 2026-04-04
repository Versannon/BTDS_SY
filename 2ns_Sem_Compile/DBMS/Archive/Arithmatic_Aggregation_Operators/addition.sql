SELECT
    item_name,
    unit_price,
    discount_amount,
    unit_price + discount_amount AS added_value
FROM sales_data;
