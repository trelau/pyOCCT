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
#include <BRepLib_MakeShape.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepLib_ShellError.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepLib_MakeShell.hxx>

void bind_BRepLib_MakeShell(py::module &mod){

py::class_<BRepLib_MakeShell, std::unique_ptr<BRepLib_MakeShell, Deleter<BRepLib_MakeShell>>, BRepLib_MakeShape> cls_BRepLib_MakeShell(mod, "BRepLib_MakeShell", "Provides methos to build shells.");

// Constructors
cls_BRepLib_MakeShell.def(py::init<>());
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("Segment"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepLib_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));

// Fields

// Methods
// cls_BRepLib_MakeShell.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeShell::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeShell.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeShell.def("Init", [](BRepLib_MakeShell &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepLib_MakeShell.def("Init", (void (BRepLib_MakeShell::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepLib_MakeShell::Init, "Creates the shell from the surface and the min-max values.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
cls_BRepLib_MakeShell.def("Error", (BRepLib_ShellError (BRepLib_MakeShell::*)() const) &BRepLib_MakeShell::Error, "None");
cls_BRepLib_MakeShell.def("Shell", (const TopoDS_Shell & (BRepLib_MakeShell::*)() const) &BRepLib_MakeShell::Shell, "Returns the new Shell.");

// Enums

}