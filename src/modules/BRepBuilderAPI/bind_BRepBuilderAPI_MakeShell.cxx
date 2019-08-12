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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_ShellError.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepLib_MakeShell.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>

void bind_BRepBuilderAPI_MakeShell(py::module &mod){

py::class_<BRepBuilderAPI_MakeShell, std::unique_ptr<BRepBuilderAPI_MakeShell, Deleter<BRepBuilderAPI_MakeShell>>, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeShell(mod, "BRepBuilderAPI_MakeShell", "Describes functions to build a shape corresponding to the skin of a surface. Note that the term shell in the class name has the same definition as that of a shell in STEP, in other words the skin of a shape, and not a solid model defined by surface and thickness. If you want to build the second sort of shell, you must use BRepOffsetAPI_MakeOffsetShape. A shell is made of a series of faces connected by their common edges. If the underlying surface of a face is not C2 continuous and the flag Segment is True, MakeShell breaks the surface down into several faces which are all C2 continuous and which are connected along the non-regular curves on the surface. The resulting shell contains all these faces. Construction of a Shell from a non-C2 continuous Surface A MakeShell object provides a framework for: - defining the construction of a shell, - implementing the construction algorithm, and - consulting the result. Warning The connected C2 faces in the shell resulting from a decomposition of the surface are not sewn. For a sewn result, you need to use BRepOffsetAPI_Sewing. For a shell with thickness, you need to use BRepOffsetAPI_MakeOffsetShape.");

// Constructors
cls_BRepBuilderAPI_MakeShell.def(py::init<>());
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("Segment"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeShell.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShell::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeShell.def("Init", [](BRepBuilderAPI_MakeShell &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepBuilderAPI_MakeShell.def("Init", (void (BRepBuilderAPI_MakeShell::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBuilderAPI_MakeShell::Init, "Defines or redefines the arguments for the construction of a shell. The construction is initialized with the surface S, limited in the u parametric direction by the two parameter values UMin and UMax, and in the v parametric direction by the two parameter values VMin and VMax. Warning The function Error returns: - BRepBuilderAPI_ShellParametersOutOfRange when the given parameters are outside the bounds of the surface or the basis surface if S is trimmed", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
cls_BRepBuilderAPI_MakeShell.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::IsDone, "Returns true if the shell is built.");
cls_BRepBuilderAPI_MakeShell.def("Error", (BRepBuilderAPI_ShellError (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::Error, "Returns the construction status: - BRepBuilderAPI_ShellDone if the shell is built, or - another value of the BRepBuilderAPI_ShellError enumeration indicating why the construction failed. This is frequently BRepBuilderAPI_ShellParametersOutOfRange indicating that the given parameters are outside the bounds of the surface.");
cls_BRepBuilderAPI_MakeShell.def("Shell", (const TopoDS_Shell & (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::Shell, "Returns the new Shell.");

// Enums

}