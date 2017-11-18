#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlAPI_RepresentationOfShape.hxx>
#include <Vrml_Material.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlAPI_Writer.hxx>
#include <VrmlAPI.hxx>

PYBIND11_MODULE(VrmlAPI, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.VrmlConverter");
	py::module::import("OCCT.Vrml");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.TopoDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlAPI_RepresentationOfShape.hxx
	py::enum_<VrmlAPI_RepresentationOfShape>(mod, "VrmlAPI_RepresentationOfShape", "Identifies the representation of the shape written to a VRML file. The available options are : - VrmlAPI_ShadedRepresentation : the shape is translated with a shaded representation. - VrmlAPI_WireFrameRepresentation : the shape is translated with a wireframe representation. - VrmlAPI_BothRepresentation : the shape is translated to VRML format with both representations : shaded and wireframe. This is the default option.")
		.value("VrmlAPI_ShadedRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_ShadedRepresentation)
		.value("VrmlAPI_WireFrameRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_WireFrameRepresentation)
		.value("VrmlAPI_BothRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_BothRepresentation)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlAPI_Writer.hxx
	py::class_<VrmlAPI_Writer, std::unique_ptr<VrmlAPI_Writer, Deleter<VrmlAPI_Writer>>> cls_VrmlAPI_Writer(mod, "VrmlAPI_Writer", "Creates and writes VRML files from Open CASCADE shapes. A VRML file can be written to an existing VRML file or to a new one.");
	cls_VrmlAPI_Writer.def(py::init<>());
	cls_VrmlAPI_Writer.def("ResetToDefaults", (void (VrmlAPI_Writer::*)()) &VrmlAPI_Writer::ResetToDefaults, "Resets all parameters (representation, deflection) to their default values..");
	cls_VrmlAPI_Writer.def("Drawer", (opencascade::handle<VrmlConverter_Drawer> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::Drawer, "Returns drawer object");
	cls_VrmlAPI_Writer.def("SetDeflection", (void (VrmlAPI_Writer::*)(const Standard_Real)) &VrmlAPI_Writer::SetDeflection, "Sets the deflection aDef of the mesh algorithm which is used to compute the shaded representation of the translated shape. The default value is -1. When the deflection value is less than 0, the deflection is calculated from the relative size of the shaped.", py::arg("aDef"));
	cls_VrmlAPI_Writer.def("SetRepresentation", (void (VrmlAPI_Writer::*)(const VrmlAPI_RepresentationOfShape)) &VrmlAPI_Writer::SetRepresentation, "Sets the representation of the shape aRep which is written to the VRML file. The three options are : - shaded - wireframe - both shaded and wireframe (default) defined through the VrmlAPI_RepresentationOfShape enumeration.", py::arg("aRep"));
	cls_VrmlAPI_Writer.def("SetTransparencyToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const Standard_Real)) &VrmlAPI_Writer::SetTransparencyToMaterial, "Set transparency to given material", py::arg("aMaterial"), py::arg("aTransparency"));
	cls_VrmlAPI_Writer.def("SetShininessToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const Standard_Real)) &VrmlAPI_Writer::SetShininessToMaterial, "None", py::arg("aMaterial"), py::arg("aShininess"));
	cls_VrmlAPI_Writer.def("SetAmbientColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetAmbientColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
	cls_VrmlAPI_Writer.def("SetDiffuseColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetDiffuseColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
	cls_VrmlAPI_Writer.def("SetSpecularColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetSpecularColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
	cls_VrmlAPI_Writer.def("SetEmissiveColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetEmissiveColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
	cls_VrmlAPI_Writer.def("GetRepresentation", (VrmlAPI_RepresentationOfShape (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetRepresentation, "Returns the representation of the shape which is written to the VRML file. Types of representation are set through the VrmlAPI_RepresentationOfShape enumeration.");
	cls_VrmlAPI_Writer.def("GetFrontMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetFrontMaterial, "None");
	cls_VrmlAPI_Writer.def("GetPointsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetPointsMaterial, "None");
	cls_VrmlAPI_Writer.def("GetUisoMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetUisoMaterial, "None");
	cls_VrmlAPI_Writer.def("GetVisoMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetVisoMaterial, "None");
	cls_VrmlAPI_Writer.def("GetLineMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetLineMaterial, "None");
	cls_VrmlAPI_Writer.def("GetWireMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetWireMaterial, "None");
	cls_VrmlAPI_Writer.def("GetFreeBoundsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetFreeBoundsMaterial, "None");
	cls_VrmlAPI_Writer.def("GetUnfreeBoundsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const ) &VrmlAPI_Writer::GetUnfreeBoundsMaterial, "None");
	cls_VrmlAPI_Writer.def("Write", [](VrmlAPI_Writer &self, const TopoDS_Shape & a0, const Standard_CString a1) -> void { return self.Write(a0, a1); }, py::arg("aShape"), py::arg("aFile"));
	cls_VrmlAPI_Writer.def("Write", (void (VrmlAPI_Writer::*)(const TopoDS_Shape &, const Standard_CString, const Standard_Integer) const ) &VrmlAPI_Writer::Write, "Converts the shape aShape to VRML format of the passed version and writes it to the file identified by aFile.", py::arg("aShape"), py::arg("aFile"), py::arg("aVersion"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\VrmlAPI.hxx
	py::class_<VrmlAPI, std::unique_ptr<VrmlAPI, Deleter<VrmlAPI>>> cls_VrmlAPI(mod, "VrmlAPI", "API for writing to VRML 1.0");
	cls_VrmlAPI.def(py::init<>());
	cls_VrmlAPI.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> void { return VrmlAPI::Write(a0, a1); }, py::arg("aShape"), py::arg("aFileName"));
	cls_VrmlAPI.def_static("Write_", (void (*)(const TopoDS_Shape &, const Standard_CString, const Standard_Integer)) &VrmlAPI::Write, "With help of this class user can change parameters of writing. Converts the shape aShape to VRML format of the passed version and writes it to the file identified by aFileName using default parameters.", py::arg("aShape"), py::arg("aFileName"), py::arg("aVersion"));


}
