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
#include <Standard.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ColorType.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <XCAFDoc_Location.hxx>
#include <XCAFDoc_Color.hxx>
#include <XCAFDoc_DimTol.hxx>
#include <XCAFDoc_Datum.hxx>
#include <XCAFDoc_Material.hxx>
#include <XCAFDoc_Volume.hxx>
#include <XCAFDoc_Area.hxx>
#include <XCAFDoc_Centroid.hxx>
#include <XCAFDoc_ClippingPlaneTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_ShapeMapTool.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <XCAFDoc_LayerTool.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_GraphNode.hxx>
#include <XCAFDoc_Editor.hxx>
#include <XCAFDoc_ViewTool.hxx>
#include <XCAFDoc.hxx>

void bind_XCAFDoc(py::module &mod){

py::class_<XCAFDoc, std::unique_ptr<XCAFDoc>> cls_XCAFDoc(mod, "XCAFDoc", "Definition of general structure of DECAF document and tools to work with it");

// Constructors

// Fields

// Methods
// cls_XCAFDoc.def_static("operator new_", (void * (*)(size_t)) &XCAFDoc::operator new, "None", py::arg("theSize"));
// cls_XCAFDoc.def_static("operator delete_", (void (*)(void *)) &XCAFDoc::operator delete, "None", py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator new[]_", (void * (*)(size_t)) &XCAFDoc::operator new[], "None", py::arg("theSize"));
// cls_XCAFDoc.def_static("operator delete[]_", (void (*)(void *)) &XCAFDoc::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFDoc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFDoc.def_static("operator delete_", (void (*)(void *, void *)) &XCAFDoc::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFDoc.def_static("AssemblyGUID_", (Standard_GUID (*)()) &XCAFDoc::AssemblyGUID, "class for containing GraphNodes. Returns GUID for UAttribute identifying assembly");
cls_XCAFDoc.def_static("ShapeRefGUID_", (Standard_GUID (*)()) &XCAFDoc::ShapeRefGUID, "Returns GUID for TreeNode representing assembly link");
cls_XCAFDoc.def_static("ColorRefGUID_", (Standard_GUID (*)(const XCAFDoc_ColorType)) &XCAFDoc::ColorRefGUID, "Return GUIDs for TreeNode representing specified types of colors", py::arg("type"));
cls_XCAFDoc.def_static("DimTolRefGUID_", (Standard_GUID (*)()) &XCAFDoc::DimTolRefGUID, "Return GUIDs for TreeNode representing specified types of DGT");
cls_XCAFDoc.def_static("DimensionRefFirstGUID_", (Standard_GUID (*)()) &XCAFDoc::DimensionRefFirstGUID, "Return GUIDs for TreeNode representing specified types of Dimension");
cls_XCAFDoc.def_static("DimensionRefSecondGUID_", (Standard_GUID (*)()) &XCAFDoc::DimensionRefSecondGUID, "Return GUIDs for TreeNode representing specified types of Dimension");
cls_XCAFDoc.def_static("GeomToleranceRefGUID_", (Standard_GUID (*)()) &XCAFDoc::GeomToleranceRefGUID, "Return GUIDs for TreeNode representing specified types of GeomTolerance");
cls_XCAFDoc.def_static("DatumRefGUID_", (Standard_GUID (*)()) &XCAFDoc::DatumRefGUID, "Return GUIDs for TreeNode representing specified types of datum");
cls_XCAFDoc.def_static("DatumTolRefGUID_", (Standard_GUID (*)()) &XCAFDoc::DatumTolRefGUID, "Return GUIDs for TreeNode representing connections Datum-Toler");
cls_XCAFDoc.def_static("LayerRefGUID_", (Standard_GUID (*)()) &XCAFDoc::LayerRefGUID, "None");
cls_XCAFDoc.def_static("MaterialRefGUID_", (Standard_GUID (*)()) &XCAFDoc::MaterialRefGUID, "None");
cls_XCAFDoc.def_static("NoteRefGUID_", (Standard_GUID (*)()) &XCAFDoc::NoteRefGUID, "Return GUIDs for representing notes");
cls_XCAFDoc.def_static("InvisibleGUID_", (Standard_GUID (*)()) &XCAFDoc::InvisibleGUID, "None");
cls_XCAFDoc.def_static("ColorByLayerGUID_", (Standard_GUID (*)()) &XCAFDoc::ColorByLayerGUID, "None");
cls_XCAFDoc.def_static("ExternRefGUID_", (Standard_GUID (*)()) &XCAFDoc::ExternRefGUID, "Returns GUID for UAttribute identifying external reference on no-step file");
cls_XCAFDoc.def_static("SHUORefGUID_", (Standard_GUID (*)()) &XCAFDoc::SHUORefGUID, "Returns GUID for UAttribute identifying specified higher usage occurrence");
cls_XCAFDoc.def_static("ViewRefGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefShapeGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefShapeGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefGDTGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefGDTGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefPlaneGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefPlaneGUID, "Return GUIDs for TreeNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefNoteGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefNoteGUID, "Return GUIDs for GraphNode representing specified types of View");
cls_XCAFDoc.def_static("ViewRefAnnotationGUID_", (Standard_GUID (*)()) &XCAFDoc::ViewRefAnnotationGUID, "None");
cls_XCAFDoc.def_static("LockGUID_", (Standard_GUID (*)()) &XCAFDoc::LockGUID, "Returns GUID for UAttribute identifying lock flag");

// Enums

}