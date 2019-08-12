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
#include <Graphic3d_Structure.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Root.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_Group.hxx>

void bind_Prs3d_Presentation(py::module &mod){

py::class_<Prs3d_Presentation, opencascade::handle<Prs3d_Presentation>, Graphic3d_Structure> cls_Prs3d_Presentation(mod, "Prs3d_Presentation", "Defines a presentation object which can be displayed, highlighted or erased. The presentation object stores the results of the presentation algorithms as defined in the StdPrs classes and the Prs3d classes inheriting Prs3d_Root. This presentation object is used to give display attributes defined at this level to ApplicationInteractiveServices classes at the level above. A presentation object is attached to a given Viewer.");

// Constructors
cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theStructManager"));
cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const Standard_Boolean>(), py::arg("theStructManager"), py::arg("theToInit"));
cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Prs3d_Presentation> &>(), py::arg("theStructManager"), py::arg("thePrs"));

// Fields

// Methods
cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Prs3d_Presentation::Compute, "None", py::arg("aProjector"));
cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"));
cls_Prs3d_Presentation.def("Compute", (void (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"), py::arg("aStructure"));
cls_Prs3d_Presentation.def("Compute", (void (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
cls_Prs3d_Presentation.def("Connect", (void (Prs3d_Presentation::*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Presentation::Connect, "None", py::arg("aPresentation"));
cls_Prs3d_Presentation.def("Remove", (void (Prs3d_Presentation::*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Presentation::Remove, "None", py::arg("aPresentation"));
cls_Prs3d_Presentation.def("RemoveAll", (void (Prs3d_Presentation::*)()) &Prs3d_Presentation::RemoveAll, "None");
cls_Prs3d_Presentation.def_static("get_type_name_", (const char * (*)()) &Prs3d_Presentation::get_type_name, "None");
cls_Prs3d_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_Presentation::get_type_descriptor, "None");
cls_Prs3d_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_Presentation::*)() const) &Prs3d_Presentation::DynamicType, "None");

// Enums

}