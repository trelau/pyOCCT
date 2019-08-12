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
#include <Graphic3d_Group.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Root.hxx>

void bind_Prs3d_Root(py::module &mod){

py::class_<Prs3d_Root, std::unique_ptr<Prs3d_Root, Deleter<Prs3d_Root>>> cls_Prs3d_Root(mod, "Prs3d_Root", "A root class for the standard presentation algorithms of the StdPrs package.");

// Constructors

// Fields

// Methods
// cls_Prs3d_Root.def_static("operator new_", (void * (*)(size_t)) &Prs3d_Root::operator new, "None", py::arg("theSize"));
// cls_Prs3d_Root.def_static("operator delete_", (void (*)(void *)) &Prs3d_Root::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d_Root.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d_Root::operator new[], "None", py::arg("theSize"));
// cls_Prs3d_Root.def_static("operator delete[]_", (void (*)(void *)) &Prs3d_Root::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d_Root.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d_Root.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d_Root.def_static("CurrentGroup_", (opencascade::handle<Graphic3d_Group> (*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Root::CurrentGroup, "Returns the current (last created) group of primititves inside graphic objects in the display. A group also contains the attributes whose ranges are limited to the primitives in it.", py::arg("thePrs3d"));
cls_Prs3d_Root.def_static("NewGroup_", (opencascade::handle<Graphic3d_Group> (*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Root::NewGroup, "Returns the new group of primitives inside graphic objects in the display. A group also contains the attributes whose ranges are limited to the primitives in it.", py::arg("thePrs3d"));

// Enums

}