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
#include <BRepFeat_Builder.hxx>
#include <Standard.hxx>
#include <gp_Ax1.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepFeat_Status.hxx>
#include <TopoDS_Face.hxx>
#include <BRepFeat_MakeCylindricalHole.hxx>

void bind_BRepFeat_MakeCylindricalHole(py::module &mod){

py::class_<BRepFeat_MakeCylindricalHole, std::unique_ptr<BRepFeat_MakeCylindricalHole, Deleter<BRepFeat_MakeCylindricalHole>>, BRepFeat_Builder> cls_BRepFeat_MakeCylindricalHole(mod, "BRepFeat_MakeCylindricalHole", "Provides a tool to make cylindrical holes on a shape.");

// Constructors
cls_BRepFeat_MakeCylindricalHole.def(py::init<>());

// Fields

// Methods
// cls_BRepFeat_MakeCylindricalHole.def_static("operator new_", (void * (*)(size_t)) &BRepFeat_MakeCylindricalHole::operator new, "None", py::arg("theSize"));
// cls_BRepFeat_MakeCylindricalHole.def_static("operator delete_", (void (*)(void *)) &BRepFeat_MakeCylindricalHole::operator delete, "None", py::arg("theAddress"));
// cls_BRepFeat_MakeCylindricalHole.def_static("operator new[]_", (void * (*)(size_t)) &BRepFeat_MakeCylindricalHole::operator new[], "None", py::arg("theSize"));
// cls_BRepFeat_MakeCylindricalHole.def_static("operator delete[]_", (void (*)(void *)) &BRepFeat_MakeCylindricalHole::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFeat_MakeCylindricalHole.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFeat_MakeCylindricalHole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFeat_MakeCylindricalHole.def_static("operator delete_", (void (*)(void *, void *)) &BRepFeat_MakeCylindricalHole::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFeat_MakeCylindricalHole.def("Init", (void (BRepFeat_MakeCylindricalHole::*)(const gp_Ax1 &)) &BRepFeat_MakeCylindricalHole::Init, "Sets the axis of the hole(s).", py::arg("Axis"));
cls_BRepFeat_MakeCylindricalHole.def("Init", (void (BRepFeat_MakeCylindricalHole::*)(const TopoDS_Shape &, const gp_Ax1 &)) &BRepFeat_MakeCylindricalHole::Init, "Sets the shape and axis on which hole(s) will be performed.", py::arg("S"), py::arg("Axis"));
cls_BRepFeat_MakeCylindricalHole.def("Perform", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real)) &BRepFeat_MakeCylindricalHole::Perform, "Performs every holes of radius <Radius>. This command has the same effect as a cut operation with an infinite cylinder defined by the given axis and <Radius>.", py::arg("Radius"));
cls_BRepFeat_MakeCylindricalHole.def("Perform", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_BRepFeat_MakeCylindricalHole.def("Perform", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::Perform, "Performs evry hole of radius <Radius> located between PFrom and PTo on the given axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("PFrom"), py::arg("PTo"), py::arg("WithControl"));
cls_BRepFeat_MakeCylindricalHole.def("PerformThruNext", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0) -> void { return self.PerformThruNext(a0); });
cls_BRepFeat_MakeCylindricalHole.def("PerformThruNext", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformThruNext, "Performs the first hole of radius <Radius>, in the direction of the defined axis. First hole signify first encountered after the origin of the axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("WithControl"));
cls_BRepFeat_MakeCylindricalHole.def("PerformUntilEnd", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0) -> void { return self.PerformUntilEnd(a0); });
cls_BRepFeat_MakeCylindricalHole.def("PerformUntilEnd", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformUntilEnd, "Performs evry holes of radius <Radius> located after the origin of the given axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("WithControl"));
cls_BRepFeat_MakeCylindricalHole.def("PerformBlind", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.PerformBlind(a0, a1); });
cls_BRepFeat_MakeCylindricalHole.def("PerformBlind", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformBlind, "Performs a blind hole of radius <Radius> and length <Length>. The length is measured from the origin of the given axis. If <WithControl> is set to Standard_False no control are done after the operation is performed.", py::arg("Radius"), py::arg("Length"), py::arg("WithControl"));
cls_BRepFeat_MakeCylindricalHole.def("Status", (BRepFeat_Status (BRepFeat_MakeCylindricalHole::*)() const) &BRepFeat_MakeCylindricalHole::Status, "Returns the status after a hole is performed.");
cls_BRepFeat_MakeCylindricalHole.def("Build", (void (BRepFeat_MakeCylindricalHole::*)()) &BRepFeat_MakeCylindricalHole::Build, "Builds the resulting shape (redefined from MakeShape). Invalidates the given parts of tools if any, and performs the result of the local operation.");

// Enums

}