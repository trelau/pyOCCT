#ifndef __SMESH_Templates_Header__
#define __SMESH_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <SMESH_Tree.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Tree.hxx
template <typename BND_BOX, int NB_CHILDREN>
void bind_SMESH_Tree(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Tree.hxx
	py::class_<SMESH_Tree<BND_BOX, NB_CHILDREN>, std::unique_ptr<SMESH_Tree<BND_BOX, NB_CHILDREN>, Deleter<SMESH_Tree<BND_BOX, NB_CHILDREN>>>> cls(mod, name.c_str(), "Base class for 2D and 3D trees");
	cls.def(py::init<>());
	cls.def(py::init<SMESH_TreeLimit *>(), py::arg("limit"));
	cls.def("compute", (void (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)()) &SMESH_Tree<BND_BOX, NB_CHILDREN>::compute, "Compute the Tree");
	cls.def("isLeaf", (bool (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)() const ) &SMESH_Tree<BND_BOX, NB_CHILDREN>::isLeaf, "Tell if Tree is a leaf or not An inheriting class can influence it via myIsLeaf protected field");
	cls.def("level", (int (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)() const ) &SMESH_Tree<BND_BOX, NB_CHILDREN>::level, "None");
	cls.def("getBox", (const SMESH_Tree<BND_BOX, NB_CHILDREN>::box_type * (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)() const ) &SMESH_Tree<BND_BOX, NB_CHILDREN>::getBox, "None");
	cls.def("getHeight", [](SMESH_Tree<BND_BOX, NB_CHILDREN> &self) -> int { return self.getHeight(); });
	cls.def("getHeight", (int (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)(const bool) const ) &SMESH_Tree<BND_BOX, NB_CHILDREN>::getHeight, "Return height of the tree, full or from this level to topest leaf", py::arg("full"));
	cls.def_static("nbChildren_", (int (*)()) &SMESH_Tree<BND_BOX, NB_CHILDREN>::nbChildren, "None");
	cls.def("maxSize", (double (SMESH_Tree<BND_BOX, NB_CHILDREN>::*)() const ) &SMESH_Tree<BND_BOX, NB_CHILDREN>::maxSize, "None");

};

#endif