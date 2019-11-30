/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <VrmlAPI_RepresentationOfShape.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlAPI_Writer.hxx>
#include <VrmlAPI.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <Vrml_Material.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TDocStd_Document.hxx>
#include <VrmlConverter_Projector.hxx>

PYBIND11_MODULE(VrmlAPI, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.VrmlConverter");
py::module::import("OCCT.Vrml");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TDocStd");

// ENUM: VRMLAPI_REPRESENTATIONOFSHAPE
py::enum_<VrmlAPI_RepresentationOfShape>(mod, "VrmlAPI_RepresentationOfShape", "Identifies the representation of the shape written to a VRML file. The available options are : - VrmlAPI_ShadedRepresentation : the shape is translated with a shaded representation. - VrmlAPI_WireFrameRepresentation : the shape is translated with a wireframe representation. - VrmlAPI_BothRepresentation : the shape is translated to VRML format with both representations : shaded and wireframe. This is the default option.")
	.value("VrmlAPI_ShadedRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_ShadedRepresentation)
	.value("VrmlAPI_WireFrameRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_WireFrameRepresentation)
	.value("VrmlAPI_BothRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_BothRepresentation)
	.export_values();


// CLASS: VRMLAPI
py::class_<VrmlAPI> cls_VrmlAPI(mod, "VrmlAPI", "API for writing to VRML 1.0");

// Methods
// cls_VrmlAPI.def_static("operator new_", (void * (*)(size_t)) &VrmlAPI::operator new, "None", py::arg("theSize"));
// cls_VrmlAPI.def_static("operator delete_", (void (*)(void *)) &VrmlAPI::operator delete, "None", py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator new[]_", (void * (*)(size_t)) &VrmlAPI::operator new[], "None", py::arg("theSize"));
// cls_VrmlAPI.def_static("operator delete[]_", (void (*)(void *)) &VrmlAPI::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator delete_", (void (*)(void *, void *)) &VrmlAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlAPI.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> Standard_Boolean { return VrmlAPI::Write(a0, a1); });
cls_VrmlAPI.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString, const Standard_Integer)) &VrmlAPI::Write, "With help of this class user can change parameters of writing. Converts the shape aShape to VRML format of the passed version and writes it to the file identified by aFileName using default parameters.", py::arg("aShape"), py::arg("aFileName"), py::arg("aVersion"));

// CLASS: VRMLAPI_WRITER
py::class_<VrmlAPI_Writer> cls_VrmlAPI_Writer(mod, "VrmlAPI_Writer", "Creates and writes VRML files from Open CASCADE shapes. A VRML file can be written to an existing VRML file or to a new one.");

// Constructors
cls_VrmlAPI_Writer.def(py::init<>());

// Methods
// cls_VrmlAPI_Writer.def_static("operator new_", (void * (*)(size_t)) &VrmlAPI_Writer::operator new, "None", py::arg("theSize"));
// cls_VrmlAPI_Writer.def_static("operator delete_", (void (*)(void *)) &VrmlAPI_Writer::operator delete, "None", py::arg("theAddress"));
// cls_VrmlAPI_Writer.def_static("operator new[]_", (void * (*)(size_t)) &VrmlAPI_Writer::operator new[], "None", py::arg("theSize"));
// cls_VrmlAPI_Writer.def_static("operator delete[]_", (void (*)(void *)) &VrmlAPI_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlAPI_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlAPI_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlAPI_Writer.def_static("operator delete_", (void (*)(void *, void *)) &VrmlAPI_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlAPI_Writer.def("ResetToDefaults", (void (VrmlAPI_Writer::*)()) &VrmlAPI_Writer::ResetToDefaults, "Resets all parameters (representation, deflection) to their default values..");
cls_VrmlAPI_Writer.def("Drawer", (opencascade::handle<VrmlConverter_Drawer> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::Drawer, "Returns drawer object");
cls_VrmlAPI_Writer.def("SetDeflection", (void (VrmlAPI_Writer::*)(const Standard_Real)) &VrmlAPI_Writer::SetDeflection, "Sets the deflection aDef of the mesh algorithm which is used to compute the shaded representation of the translated shape. The default value is -1. When the deflection value is less than 0, the deflection is calculated from the relative size of the shaped.", py::arg("aDef"));
cls_VrmlAPI_Writer.def("SetRepresentation", (void (VrmlAPI_Writer::*)(const VrmlAPI_RepresentationOfShape)) &VrmlAPI_Writer::SetRepresentation, "Sets the representation of the shape aRep which is written to the VRML file. The three options are : - shaded - wireframe - both shaded and wireframe (default) defined through the VrmlAPI_RepresentationOfShape enumeration.", py::arg("aRep"));
cls_VrmlAPI_Writer.def("SetTransparencyToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const Standard_Real)) &VrmlAPI_Writer::SetTransparencyToMaterial, "Set transparency to given material", py::arg("aMaterial"), py::arg("aTransparency"));
cls_VrmlAPI_Writer.def("SetShininessToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const Standard_Real)) &VrmlAPI_Writer::SetShininessToMaterial, "None", py::arg("aMaterial"), py::arg("aShininess"));
cls_VrmlAPI_Writer.def("SetAmbientColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetAmbientColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
cls_VrmlAPI_Writer.def("SetDiffuseColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetDiffuseColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
cls_VrmlAPI_Writer.def("SetSpecularColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetSpecularColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
cls_VrmlAPI_Writer.def("SetEmissiveColorToMaterial", (void (VrmlAPI_Writer::*)(opencascade::handle<Vrml_Material> &, const opencascade::handle<Quantity_HArray1OfColor> &)) &VrmlAPI_Writer::SetEmissiveColorToMaterial, "None", py::arg("aMaterial"), py::arg("Color"));
cls_VrmlAPI_Writer.def("GetRepresentation", (VrmlAPI_RepresentationOfShape (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetRepresentation, "Returns the representation of the shape which is written to the VRML file. Types of representation are set through the VrmlAPI_RepresentationOfShape enumeration.");
cls_VrmlAPI_Writer.def("GetFrontMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetFrontMaterial, "None");
cls_VrmlAPI_Writer.def("GetPointsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetPointsMaterial, "None");
cls_VrmlAPI_Writer.def("GetUisoMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetUisoMaterial, "None");
cls_VrmlAPI_Writer.def("GetVisoMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetVisoMaterial, "None");
cls_VrmlAPI_Writer.def("GetLineMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetLineMaterial, "None");
cls_VrmlAPI_Writer.def("GetWireMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetWireMaterial, "None");
cls_VrmlAPI_Writer.def("GetFreeBoundsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetFreeBoundsMaterial, "None");
cls_VrmlAPI_Writer.def("GetUnfreeBoundsMaterial", (opencascade::handle<Vrml_Material> (VrmlAPI_Writer::*)() const) &VrmlAPI_Writer::GetUnfreeBoundsMaterial, "None");
cls_VrmlAPI_Writer.def("Write", [](VrmlAPI_Writer &self, const TopoDS_Shape & a0, const Standard_CString a1) -> Standard_Boolean { return self.Write(a0, a1); });
cls_VrmlAPI_Writer.def("Write", (Standard_Boolean (VrmlAPI_Writer::*)(const TopoDS_Shape &, const Standard_CString, const Standard_Integer) const) &VrmlAPI_Writer::Write, "Converts the shape aShape to VRML format of the passed version and writes it to the file identified by aFile.", py::arg("aShape"), py::arg("aFile"), py::arg("aVersion"));
cls_VrmlAPI_Writer.def("WriteDoc", (Standard_Boolean (VrmlAPI_Writer::*)(const opencascade::handle<TDocStd_Document> &, const Standard_CString, const Standard_Real) const) &VrmlAPI_Writer::WriteDoc, "Converts the document to VRML format of the passed version and writes it to the file identified by aFile.", py::arg("theDoc"), py::arg("theFile"), py::arg("theScale"));


}
