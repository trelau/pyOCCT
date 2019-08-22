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
#include <Standard_Handle.hxx>
#include <IGESBasic_Protocol.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <IGESBasic_Group.hxx>
#include <IGESBasic_GroupWithoutBackP.hxx>
#include <IGESBasic_SingleParent.hxx>
#include <IGESBasic_ExternalRefFileIndex.hxx>
#include <IGESBasic_OrderedGroup.hxx>
#include <IGESBasic_OrderedGroupWithoutBackP.hxx>
#include <IGESBasic_Hierarchy.hxx>
#include <IGESBasic_ExternalReferenceFile.hxx>
#include <IGESBasic_Name.hxx>
#include <IGESBasic_AssocGroupType.hxx>
#include <IGESBasic_SingularSubfigure.hxx>
#include <IGESBasic_ExternalRefFileName.hxx>
#include <IGESBasic_ExternalRefFile.hxx>
#include <IGESBasic_ExternalRefName.hxx>
#include <IGESBasic_ExternalRefLibName.hxx>
#include <IGESBasic_ToolSubfigureDef.hxx>
#include <IGESBasic_ToolGroup.hxx>
#include <IGESBasic_ToolGroupWithoutBackP.hxx>
#include <IGESBasic_ToolSingleParent.hxx>
#include <IGESBasic_ToolExternalRefFileIndex.hxx>
#include <IGESBasic_ToolOrderedGroup.hxx>
#include <IGESBasic_ToolOrderedGroupWithoutBackP.hxx>
#include <IGESBasic_ToolHierarchy.hxx>
#include <IGESBasic_ToolExternalReferenceFile.hxx>
#include <IGESBasic_ToolName.hxx>
#include <IGESBasic_ToolAssocGroupType.hxx>
#include <IGESBasic_ToolSingularSubfigure.hxx>
#include <IGESBasic_ToolExternalRefFileName.hxx>
#include <IGESBasic_ToolExternalRefFile.hxx>
#include <IGESBasic_ToolExternalRefName.hxx>
#include <IGESBasic_ToolExternalRefLibName.hxx>
#include <IGESBasic_ReadWriteModule.hxx>
#include <IGESBasic_GeneralModule.hxx>
#include <IGESBasic_SpecificModule.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <IGESBasic_HArray1OfHArray1OfXY.hxx>
#include <IGESBasic_HArray1OfHArray1OfXYZ.hxx>
#include <IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <IGESBasic.hxx>

void bind_IGESBasic(py::module &mod){

py::class_<IGESBasic> cls_IGESBasic(mod, "IGESBasic", "This package represents basic entities from IGES");

// Constructors

// Fields

// Methods
// cls_IGESBasic.def_static("operator new_", (void * (*)(size_t)) &IGESBasic::operator new, "None", py::arg("theSize"));
// cls_IGESBasic.def_static("operator delete_", (void (*)(void *)) &IGESBasic::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic.def_static("Init_", (void (*)()) &IGESBasic::Init, "Prepares dynqmic data (Protocol, Modules) for this package");
cls_IGESBasic.def_static("Protocol_", (opencascade::handle<IGESBasic_Protocol> (*)()) &IGESBasic::Protocol, "Returns the Protocol for this Package");

// Enums

}