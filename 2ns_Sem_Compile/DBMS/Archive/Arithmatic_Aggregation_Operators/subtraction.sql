SELECT
    item_name,
    unit_price,
    discount_amount,
    unit_price - discount_amount AS net_price
FROM sales_data;
