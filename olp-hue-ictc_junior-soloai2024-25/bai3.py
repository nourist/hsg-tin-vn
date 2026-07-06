# Hàm tính tổng XOR từ 1 đến limit
def xor_sum_range(x, y, num_vars=4):
    def count_bit_xor_sum(limit: int, num_vars: int = 4):
        if limit < 1:
            return 0

        total_xor_sum = 0
        max_bit = limit.bit_length()

        for bit in range(max_bit):
            bit_count = (limit + 1) // (1 << (bit + 1)) * (1 << bit) + \
                        max(0, (limit + 1) % (1 << (bit + 1)) - (1 << bit))

            contribution = bit_count * (limit ** (num_vars - 1))
            total_xor_sum += contribution * (1 << bit)

        return total_xor_sum

    return count_bit_xor_sum(y, num_vars) - count_bit_xor_sum(x - 1, num_vars)


# Thử nghiệm với x = 50, y = 100
x, y = map(int, input().split())
result_range = xor_sum_range(x, y)
print(result_range)
