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
#include <Prs3d_Root.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Bnd_Box.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdPrs_BndBox.hxx>

void bind_StdPrs_BndBox(py::module &mod){

py::class_<StdPrs_BndBox, std::unique_ptr<StdPrs_BndBox, Deleter<StdPrs_BndBox>>, Prs3d_Root> cls_StdPrs_BndBox(mod, "StdPrs_BndBox", "Tool for computing bounding box presentation.");

// Constructors

// Fields

// Methods
cls_StdPrs_BndBox.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Bnd_Box &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_BndBox::Add, "Computes presentation of a bounding box.", py::arg("thePresentation"), py::arg("theBndBox"), py::arg("theDrawer"));

// Enums

}