# My42Piscine

This repository contains my solutions and test programs for 42 C Piscine & exam preparation.

## 📂 Structure

```
exercises/
  ├── aff_first_param/
  ├── aff_last_param/
  ├── count_alpha/
  ├── count_island/
  ├── even/
  ├── first_word/
  ├── ft_add/
  ├── ft_atoi/
  ├── ft_countdown/
  ├── ft_dec/
  ├── ft_ft/
  ├── ft_inc/
  ├── ft_itoa/
  ├── ft_list_foreach/
  ├── ft_list_push_back/
  ├── ft_list_remove_if/
  ├── ft_list_size/
  ├── ft_mul/
  ├── ft_print_list/
  ├── ft_print_numbers/
  ├── ft_putnbr/
  ├── ft_range/
  ├── ft_rrange/
  ├── ft_split/
  ├── ft_star/
  ├── ft_strcmp/
  ├── ft_strcpy/
  ├── ft_strrev/
  ├── ft_sub/
  ├── ft_swap/
  ├── hello/
  ├── inc_elem/
  ├── inter/
  ├── is_palindrome/
  ├── maff_alpha/
  ├── maff_revalpha/
  └── tests/
      ├── test_big_number_multiply.c
      ├── test_ft_add.c
      ├── test_ft_atoi.c
      ├── test_ft_dec.c
      ├── test_ft_inc.c
      ├── test_ft_itoa.c
      ├── test_ft_list_remove_if.c
      ├── test_ft_list_size.c
      ├── test_ft_mul.c
      ├── test_ft_print_numbers.c
      ├── test_ft_putnbr.c
      ├── test_ft_putstr.c
      ├── test_ft_range.c
      ├── test_ft_rrange.c
      ├── test_ft_split.c
      ├── test_ft_strcmp.c
      ├── test_ft_strcpy.c
      ├── test_ft_strlen.c
      ├── test_ft_strrev.c
      ├── test_ft_sub.c
      ├── test_ft_swap.c
      ├── test_graph_diameter.c
      ├── test_ord_alphlong.c
      ├── test_sort_list.c
      ├── test_swap_cases.c
      └── test_occurrence_counter.c
```

## 🧪 Test Programs

Each file in `exercises/tests/` is a standalone `main()` to test one or more functions:

- `test_ft_add.c` → tests `ft_add`
- `test_ft_atoi.c` → tests `ft_atoi`
- `test_ft_range.c` → tests `ft_range`
- `test_ft_rrange.c` → tests `ft_rrange`
- `test_ft_split.c` → tests `ft_split`
- `test_ft_strcmp.c` → tests `ft_strcmp`
- `test_ft_strcpy.c` → tests `ft_strcpy`
- `test_ft_strrev.c` → tests `ft_strrev`
- `test_ft_sub.c` → tests `ft_sub`
- `test_ft_swap.c` → tests `ft_swap`
- `test_ft_dec.c` → tests `ft_dec`
- `test_ft_inc.c` → tests `ft_inc`
- `test_ft_mul.c` → tests `ft_mul`
- `test_ft_itoa.c` → tests `ft_itoa`
- `test_ft_strlen.c` → tests `ft_strlen`
- `test_ft_putnbr.c` → tests `ft_putnbr`
- `test_ft_putstr.c` → tests `ft_putstr`
- `test_ft_print_numbers.c` → tests `ft_print_numbers`
- `test_ord_alphlong.c` → tests `ord_alphlong` (word sorting)
- `test_sort_list.c` → tests `sort_list` (linked list)
- `test_ft_list_size.c` → tests `ft_list_size`
- `test_ft_list_remove_if.c` → tests `ft_list_remove_if`
- `test_swap_cases.c` → tests `swap_cases`
- `test_occurrence_counter.c` → tests occurrence counting
- `test_big_number_multiply.c` → tests big integer multiplication
- `test_graph_diameter.c` → tests graph diameter (`g_diam`)

## ⚙️ Usage

To compile a specific test:

```bash
gcc exercises/tests/test_ft_split.c exercises/ft_split/ft_split.c -o test_split
./test_split "Hello 42 Piscine"
```
