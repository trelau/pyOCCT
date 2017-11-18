#ifndef __SMESHDS_Templates_Header__
#define __SMESHDS_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <SMDS_Iterator.hxx>
#include <SMESHDS_TSubMeshHolder.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_TSubMeshHolder.hxx
template <typename SUBMESH>
void bind_SMESHDS_TSubMeshHolder(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESHDS_TSubMeshHolder.hxx
	py::class_<SMESHDS_TSubMeshHolder<SUBMESH>, std::unique_ptr<SMESHDS_TSubMeshHolder<SUBMESH>, Deleter<SMESHDS_TSubMeshHolder<SUBMESH>>>> cls(mod, name.c_str(), "A binder of a sub-mesh to its ID which can be negative. Provides fast access to a sub-mesh by its ID.");
	cls.def(py::init<>());
	cls.def("Add", (void (SMESHDS_TSubMeshHolder<SUBMESH>::*)(int, SUBMESH *)) &SMESHDS_TSubMeshHolder<SUBMESH>::Add, "None", py::arg("id"), py::arg("sm"));
	cls.def("Get", (SUBMESH * (SMESHDS_TSubMeshHolder<SUBMESH>::*)(int) const ) &SMESHDS_TSubMeshHolder<SUBMESH>::Get, "None", py::arg("id"));
	cls.def("DeleteAll", (void (SMESHDS_TSubMeshHolder<SUBMESH>::*)()) &SMESHDS_TSubMeshHolder<SUBMESH>::DeleteAll, "None");
	cls.def("GetMinID", (int (SMESHDS_TSubMeshHolder<SUBMESH>::*)() const ) &SMESHDS_TSubMeshHolder<SUBMESH>::GetMinID, "None");
	cls.def("GetMaxID", (int (SMESHDS_TSubMeshHolder<SUBMESH>::*)() const ) &SMESHDS_TSubMeshHolder<SUBMESH>::GetMaxID, "None");
	cls.def("GetIterator", [](SMESHDS_TSubMeshHolder<SUBMESH> &self) -> SMDS_Iterator<SUBMESH *> * { return self.GetIterator(); });
	cls.def("GetIterator", (SMDS_Iterator<SUBMESH *> * (SMESHDS_TSubMeshHolder<SUBMESH>::*)(const bool) const ) &SMESHDS_TSubMeshHolder<SUBMESH>::GetIterator, "None", py::arg("reverse"));

};

#endif