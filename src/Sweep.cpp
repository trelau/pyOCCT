/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Sweep_NumShape.hxx>
#include <Sweep_NumShapeTool.hxx>
#include <Sweep_NumShapeIterator.hxx>

PYBIND11_MODULE(Sweep, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Sweep_NumShape.hxx
	py::class_<Sweep_NumShape, std::unique_ptr<Sweep_NumShape, Deleter<Sweep_NumShape>>> cls_Sweep_NumShape(mod, "Sweep_NumShape", "Gives a simple indexed representation of a Directing Edge topology.");
	cls_Sweep_NumShape.def(py::init<>());
	cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum>(), py::arg("Index"), py::arg("Type"));
	cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"));
	cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"));
	cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"), py::arg("EndInf"));
	cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); }, py::arg("Index"), py::arg("Type"));
	cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); }, py::arg("Index"), py::arg("Type"), py::arg("Closed"));
	cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); }, py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"));
	cls_Sweep_NumShape.def("Init", (void (Sweep_NumShape::*)(const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &Sweep_NumShape::Init, "Reinitialize a simple indexed edge.", py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"), py::arg("EndInf"));
	cls_Sweep_NumShape.def("Index", (Standard_Integer (Sweep_NumShape::*)() const ) &Sweep_NumShape::Index, "None");
	cls_Sweep_NumShape.def("Type", (TopAbs_ShapeEnum (Sweep_NumShape::*)() const ) &Sweep_NumShape::Type, "None");
	cls_Sweep_NumShape.def("Closed", (Standard_Boolean (Sweep_NumShape::*)() const ) &Sweep_NumShape::Closed, "None");
	cls_Sweep_NumShape.def("BegInfinite", (Standard_Boolean (Sweep_NumShape::*)() const ) &Sweep_NumShape::BegInfinite, "None");
	cls_Sweep_NumShape.def("EndInfinite", (Standard_Boolean (Sweep_NumShape::*)() const ) &Sweep_NumShape::EndInfinite, "None");
	cls_Sweep_NumShape.def("Orientation", (TopAbs_Orientation (Sweep_NumShape::*)() const ) &Sweep_NumShape::Orientation, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Sweep_NumShapeTool.hxx
	py::class_<Sweep_NumShapeTool, std::unique_ptr<Sweep_NumShapeTool, Deleter<Sweep_NumShapeTool>>> cls_Sweep_NumShapeTool(mod, "Sweep_NumShapeTool", "This class provides the indexation and type analysis services required by the NumShape Directing Shapes of Swept Primitives.");
	cls_Sweep_NumShapeTool.def(py::init<const Sweep_NumShape &>(), py::arg("aShape"));
	cls_Sweep_NumShapeTool.def("NbShapes", (Standard_Integer (Sweep_NumShapeTool::*)() const ) &Sweep_NumShapeTool::NbShapes, "Returns the number of subshapes in the shape.");
	cls_Sweep_NumShapeTool.def("Index", (Standard_Integer (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const ) &Sweep_NumShapeTool::Index, "Returns the index of <aShape>.", py::arg("aShape"));
	cls_Sweep_NumShapeTool.def("Shape", (Sweep_NumShape (Sweep_NumShapeTool::*)(const Standard_Integer) const ) &Sweep_NumShapeTool::Shape, "Returns the Shape at index anIndex", py::arg("anIndex"));
	cls_Sweep_NumShapeTool.def("Type", (TopAbs_ShapeEnum (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const ) &Sweep_NumShapeTool::Type, "Returns the type of <aShape>.", py::arg("aShape"));
	cls_Sweep_NumShapeTool.def("Orientation", (TopAbs_Orientation (Sweep_NumShapeTool::*)(const Sweep_NumShape &) const ) &Sweep_NumShapeTool::Orientation, "Returns the orientation of <aShape>.", py::arg("aShape"));
	cls_Sweep_NumShapeTool.def("HasFirstVertex", (Standard_Boolean (Sweep_NumShapeTool::*)() const ) &Sweep_NumShapeTool::HasFirstVertex, "Returns true if there is a First Vertex in the Shape.");
	cls_Sweep_NumShapeTool.def("HasLastVertex", (Standard_Boolean (Sweep_NumShapeTool::*)() const ) &Sweep_NumShapeTool::HasLastVertex, "Returns true if there is a Last Vertex in the Shape.");
	cls_Sweep_NumShapeTool.def("FirstVertex", (Sweep_NumShape (Sweep_NumShapeTool::*)() const ) &Sweep_NumShapeTool::FirstVertex, "Returns the first vertex.");
	cls_Sweep_NumShapeTool.def("LastVertex", (Sweep_NumShape (Sweep_NumShapeTool::*)() const ) &Sweep_NumShapeTool::LastVertex, "Returns the last vertex.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Sweep_NumShapeIterator.hxx
	py::class_<Sweep_NumShapeIterator, std::unique_ptr<Sweep_NumShapeIterator, Deleter<Sweep_NumShapeIterator>>> cls_Sweep_NumShapeIterator(mod, "Sweep_NumShapeIterator", "This class provides iteration services required by the Swept Primitives for a Directing NumShape Line.");
	cls_Sweep_NumShapeIterator.def(py::init<>());
	cls_Sweep_NumShapeIterator.def("Init", (void (Sweep_NumShapeIterator::*)(const Sweep_NumShape &)) &Sweep_NumShapeIterator::Init, "Resest the NumShapeIterator on sub-shapes of <aShape>.", py::arg("aShape"));
	cls_Sweep_NumShapeIterator.def("More", (Standard_Boolean (Sweep_NumShapeIterator::*)() const ) &Sweep_NumShapeIterator::More, "Returns True if there is a current sub-shape.");
	cls_Sweep_NumShapeIterator.def("Next", (void (Sweep_NumShapeIterator::*)()) &Sweep_NumShapeIterator::Next, "Moves to the next sub-shape.");
	cls_Sweep_NumShapeIterator.def("Value", (const Sweep_NumShape & (Sweep_NumShapeIterator::*)() const ) &Sweep_NumShapeIterator::Value, "Returns the current sub-shape.");
	cls_Sweep_NumShapeIterator.def("Orientation", (TopAbs_Orientation (Sweep_NumShapeIterator::*)() const ) &Sweep_NumShapeIterator::Orientation, "Returns the orientation of the current sub-shape.");


}
