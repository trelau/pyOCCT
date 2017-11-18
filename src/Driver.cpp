#include <pyOCCT_Common.hpp>

#include <Driver_Mesh.h>
#include <SMESH_ComputeError.hxx>
#include <SMDS_Mesh.hxx>
#include <Driver_SMDS_Mesh.h>
#include <SMESHDS_Mesh.hxx>
#include <Driver_SMESHDS_Mesh.h>
#include <SMESHDS_Document.hxx>
#include <Driver_Document.h>

PYBIND11_MODULE(Driver, mod) {

	// IMPORT
	py::module::import("OCCT.SMESH");
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.SMESHDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// Callback for Driver_Mesh.
	class PyCallback_Driver_Mesh : public Driver_Mesh {
	public:
		using Driver_Mesh::Driver_Mesh;

		Driver_Mesh::Status Perform() override { PYBIND11_OVERLOAD_PURE(Driver_Mesh::Status, Driver_Mesh, Perform, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Driver_Mesh.h
	py::class_<Driver_Mesh, std::unique_ptr<Driver_Mesh, Deleter<Driver_Mesh>>, PyCallback_Driver_Mesh> cls_Driver_Mesh(mod, "Driver_Mesh", "None");
	cls_Driver_Mesh.def(py::init<>());
	cls_Driver_Mesh.def("SetMeshId", (void (Driver_Mesh::*)(int)) &Driver_Mesh::SetMeshId, "None", py::arg("theMeshId"));
	cls_Driver_Mesh.def("SetFile", (void (Driver_Mesh::*)(const std::string &)) &Driver_Mesh::SetFile, "None", py::arg("theFileName"));
	cls_Driver_Mesh.def("SetMeshName", (void (Driver_Mesh::*)(const std::string &)) &Driver_Mesh::SetMeshName, "None", py::arg("theMeshName"));
	cls_Driver_Mesh.def("GetMeshName", (std::string (Driver_Mesh::*)() const ) &Driver_Mesh::GetMeshName, "None");
	cls_Driver_Mesh.def("SetOption", (void (Driver_Mesh::*)(const std::string &, const std::string &)) &Driver_Mesh::SetOption, "None", py::arg("optionName"), py::arg("optionValue"));
	cls_Driver_Mesh.def("Perform", (Driver_Mesh::Status (Driver_Mesh::*)()) &Driver_Mesh::Perform, "None");
	cls_Driver_Mesh.def("GetError", (SMESH_ComputeErrorPtr (Driver_Mesh::*)()) &Driver_Mesh::GetError, "None");
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Driver_Mesh.h
	py::enum_<Driver_Mesh::Status>(cls_Driver_Mesh, "Status", "None")
		.value("DRS_OK", Driver_Mesh::Status::DRS_OK)
		.value("DRS_EMPTY", Driver_Mesh::Status::DRS_EMPTY)
		.value("DRS_WARN_RENUMBER", Driver_Mesh::Status::DRS_WARN_RENUMBER)
		.value("DRS_WARN_SKIP_ELEM", Driver_Mesh::Status::DRS_WARN_SKIP_ELEM)
		.value("DRS_WARN_DESCENDING", Driver_Mesh::Status::DRS_WARN_DESCENDING)
		.value("DRS_FAIL", Driver_Mesh::Status::DRS_FAIL)
		.export_values();

	// Callback for Driver_SMDS_Mesh.
	class PyCallback_Driver_SMDS_Mesh : public Driver_SMDS_Mesh {
	public:
		using Driver_SMDS_Mesh::Driver_SMDS_Mesh;

		Driver_Mesh::Status Perform() override { PYBIND11_OVERLOAD_PURE(Driver_Mesh::Status, Driver_SMDS_Mesh, Perform, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Driver_SMDS_Mesh.h
	py::class_<Driver_SMDS_Mesh, std::unique_ptr<Driver_SMDS_Mesh, Deleter<Driver_SMDS_Mesh>>, PyCallback_Driver_SMDS_Mesh, Driver_Mesh> cls_Driver_SMDS_Mesh(mod, "Driver_SMDS_Mesh", "None");
	cls_Driver_SMDS_Mesh.def(py::init<>());
	cls_Driver_SMDS_Mesh.def("SetMesh", (void (Driver_SMDS_Mesh::*)(SMDS_Mesh *)) &Driver_SMDS_Mesh::SetMesh, "None", py::arg("theMesh"));

	// Callback for Driver_SMESHDS_Mesh.
	class PyCallback_Driver_SMESHDS_Mesh : public Driver_SMESHDS_Mesh {
	public:
		using Driver_SMESHDS_Mesh::Driver_SMESHDS_Mesh;

		Driver_Mesh::Status Perform() override { PYBIND11_OVERLOAD_PURE(Driver_Mesh::Status, Driver_SMESHDS_Mesh, Perform, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Driver_SMESHDS_Mesh.h
	py::class_<Driver_SMESHDS_Mesh, std::unique_ptr<Driver_SMESHDS_Mesh, Deleter<Driver_SMESHDS_Mesh>>, PyCallback_Driver_SMESHDS_Mesh, Driver_Mesh> cls_Driver_SMESHDS_Mesh(mod, "Driver_SMESHDS_Mesh", "None");
	cls_Driver_SMESHDS_Mesh.def(py::init<>());
	cls_Driver_SMESHDS_Mesh.def("SetMesh", (void (Driver_SMESHDS_Mesh::*)(SMESHDS_Mesh *)) &Driver_SMESHDS_Mesh::SetMesh, "None", py::arg("theMesh"));

	// Callback for Driver_Document.
	class PyCallback_Driver_Document : public Driver_Document {
	public:
		using Driver_Document::Driver_Document;

		void Perform() override { PYBIND11_OVERLOAD_PURE(void, Driver_Document, Perform, ); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Driver_Document.h
	py::class_<Driver_Document, std::unique_ptr<Driver_Document, Deleter<Driver_Document>>, PyCallback_Driver_Document> cls_Driver_Document(mod, "Driver_Document", "None");
	cls_Driver_Document.def(py::init<>());
	cls_Driver_Document.def("Perform", (void (Driver_Document::*)()) &Driver_Document::Perform, "None");
	cls_Driver_Document.def("SetFile", (void (Driver_Document::*)(const std::string &)) &Driver_Document::SetFile, "None", py::arg("theFileName"));
	cls_Driver_Document.def("SetDocument", (void (Driver_Document::*)(SMESHDS_Document *)) &Driver_Document::SetDocument, "None", py::arg("theDocument"));


}
