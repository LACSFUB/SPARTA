#pragma once
#include <string>
#include "comp_mats.h"



struct reorder_parameters
{
    float tau = 0.9;
    intT block_size = 16;
    std::string algo = "saad";
};

intT count_groups(intT* grp, intT grp_len);

int grp_to_partition(intT* grp, intT grp_len, intT* partition);

int hash_permute(CSR& cmat, intT* compressed_dim_partition, intT* perm, intT* group, int mode);

intT hash(intT* arr, intT a_len, intT* block_partition, int mode);

int check_same_pattern(intT* arr0, intT len0, intT* arr1, intT len1, intT block_size, int mode);

int check_same_pattern(intT* arr0, intT len0, intT* arr1, intT len1, intT* block_partition, int mode);

int get_pattern(intT* arr0, intT len0, intT* block_partition, intT* pattern, int mode);

int angle_method(CSR& cmat, float eps, intT* compressed_dim_partition, intT nB, intT* in_perm, intT* in_group, intT* out_group, int mode);

int angle_hash_method(CSR& cmat, float eps, intT* compressed_dim_partition, intT nB, VBS& vbmat, int vbmat_blocks_fmt, int vbmat_entries_fmt, int mode);

intT row_hash(intT* cols, intT len);

intT row_block_hash(intT* cols, intT len, intT block_size);

bool equal_rows(intT* cols_A, intT len_A, intT* cols_B, intT len_B);

int hash_reordering(CSR& cmat, intT* groups, reorder_parameters &params);

int assign_group(intT* in_group, intT* out_group, intT* perm, intT jp, intT new_group_idx);

int saad_reordering(CSR& cmat, reorder_parameters &params, intT* out_group, int(*reorder_func)(CSR&, intT*, reorder_parameters&), bool(*sim_condition)(intT*, intT, intT*, intT, reorder_parameters&));

int saad_reordering(CSR& cmat, reorder_parameters& params, intT* out_group);

bool scalar_condition(intT* cols_A, intT len_A, intT* cols_B, intT len_B, reorder_parameters &params);

bool scalar_block_condition(intT* cols_A, intT len_A, intT* cols_B, intT len_B, reorder_parameters &params);

int group_to_VBS(CSR& cmat, intT* grouping, intT* compressed_dim_partition, intT nB, VBS& vbmat, int vbmat_blocks_fmt, int vbmat_entries_fmt);

