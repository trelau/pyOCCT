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
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_ShellToSolid.hxx>

void bind_TopOpeBRepBuild_ShellToSolid(py::module &mod){

py::class_<TopOpeBRepBuild_ShellToSolid, std::unique_ptr<TopOpeBRepBuild_ShellToSolid>> cls_TopOpeBRepBuild_ShellToSolid(mod, "TopOpeBRepBuild_ShellToSolid", "This class builds solids from a set of shells SSh and a solid F.");

// Constructors
cls_TopOpeBRepBuild_ShellToSolid.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellToSolid::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_ShellToSolid::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_ShellToSolid::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_ShellToSolid::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_ShellToSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_ShellToSolid.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_ShellToSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_ShellToSolid.def("Init", (void (TopOpeBRepBuild_ShellToSolid::*)()) &TopOpeBRepBuild_ShellToSolid::Init, "None");
cls_TopOpeBRepBuild_ShellToSolid.def("AddShell", (void (TopOpeBRepBuild_ShellToSolid::*)(const TopoDS_Shell &)) &TopOpeBRepBuild_ShellToSolid::AddShell, "None", py::arg("Sh"));
cls_TopOpeBRepBuild_ShellToSolid.def("MakeSolids", (void (TopOpeBRepBuild_ShellToSolid::*)(const TopoDS_Solid &, TopTools_ListOfShape &)) &TopOpeBRepBuild_ShellToSolid::MakeSolids, "None", py::arg("So"), py::arg("LSo"));

// Enums

}