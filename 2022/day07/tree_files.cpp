#include "tree_files.h"

/*
class TreeNode {
    private:
        std::string name;
        bool am_i_file;
        int filesize;
        std::vector< TreeNode * > children;
        TreeNode * parent;

};
*/

TreeNode::TreeNode(std::string new_name,
                    bool is_this_a_file,
                    int new_filesize,
                    TreeNode* new_parent){
    set_name(new_name);
    set_is_file(is_this_a_file);
    set_filesize(new_filesize);
    set_parent(new_parent);
}

std::string TreeNode::get_name(){
    return name;
}

void TreeNode::set_name(std::string new_name){
    name = new_name;
}

bool TreeNode::is_file(){
    return am_i_file;
}

bool TreeNode::is_dir(){
    return !am_i_file;
}

void TreeNode::set_is_file(bool new_value){
    am_i_file = new_value;
}

int TreeNode::get_filesize(){
    return filesize;
}

void TreeNode::set_filesize(int new_filesize){
    filesize = new_filesize;
}

void TreeNode::add_child(TreeNode * new_child){
    children.push_back(new_child);
}

TreeNode * TreeNode::get_parent(){
    return parent;
}
void TreeNode::set_parent(TreeNode * new_parent){
    parent = new_parent;
}

std::vector< TreeNode * > TreeNode::get_children(){
    return children;
}
