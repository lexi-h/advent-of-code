#ifndef TREE_FILES_H
#define TREE_FILES_H

#include <string>
#include <vector>

class TreeNode {
    private:
        std::string name;
        bool am_i_file;
        int filesize;
        std::vector< TreeNode * > children;
        TreeNode * parent;

    public:
        TreeNode(std::string new_name,
                    bool is_this_a_file,
                    int new_filesize = 0,
                    TreeNode* new_parent = NULL);
        std::string get_name();
        void set_name(std::string new_name);

        bool is_file();
        bool is_dir();
        void set_is_file(bool new_value);
        int get_filesize();
        void set_filesize(int new_filesize);
        void add_child(TreeNode * new_child);
        TreeNode * get_parent();
        void set_parent(TreeNode * new_parent);
        std::vector< TreeNode * > get_children();
    };

#endif

