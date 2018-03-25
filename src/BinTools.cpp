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
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <BinTools_LocationSet.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BinTools_SurfaceSet.hxx>
#include <Geom_Curve.hxx>
#include <BinTools_CurveSet.hxx>
#include <Geom2d_Curve.hxx>
#include <BinTools_Curve2dSet.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BinTools_ShapeSet.hxx>
#include <BinTools_LocationSetPtr.hxx>
#include <BinTools.hxx>

PYBIND11_MODULE(BinTools, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_LocationSet.hxx
	py::class_<BinTools_LocationSet, std::unique_ptr<BinTools_LocationSet, Deleter<BinTools_LocationSet>>> cls_BinTools_LocationSet(mod, "BinTools_LocationSet", "The class LocationSet stores a set of location in a relocatable state.");
	cls_BinTools_LocationSet.def(py::init<>());
	cls_BinTools_LocationSet.def("Clear", (void (BinTools_LocationSet::*)()) &BinTools_LocationSet::Clear, "Clears the content of the set.");
	cls_BinTools_LocationSet.def("Add", (Standard_Integer (BinTools_LocationSet::*)(const TopLoc_Location &)) &BinTools_LocationSet::Add, "Incorporate a new Location in the set and returns its index.", py::arg("L"));
	cls_BinTools_LocationSet.def("Location", (const TopLoc_Location & (BinTools_LocationSet::*)(const Standard_Integer) const ) &BinTools_LocationSet::Location, "Returns the location of index <I>.", py::arg("I"));
	cls_BinTools_LocationSet.def("Index", (Standard_Integer (BinTools_LocationSet::*)(const TopLoc_Location &) const ) &BinTools_LocationSet::Index, "Returns the index of <L>.", py::arg("L"));
	cls_BinTools_LocationSet.def("NbLocations", (Standard_Integer (BinTools_LocationSet::*)() const ) &BinTools_LocationSet::NbLocations, "Returns number of locations.");
	cls_BinTools_LocationSet.def("Write", (void (BinTools_LocationSet::*)(Standard_OStream &) const ) &BinTools_LocationSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_LocationSet.def("Read", (void (BinTools_LocationSet::*)(Standard_IStream &)) &BinTools_LocationSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_SurfaceSet.hxx
	py::class_<BinTools_SurfaceSet, std::unique_ptr<BinTools_SurfaceSet, Deleter<BinTools_SurfaceSet>>> cls_BinTools_SurfaceSet(mod, "BinTools_SurfaceSet", "Stores a set of Surfaces from Geom in binary format.");
	cls_BinTools_SurfaceSet.def(py::init<>());
	cls_BinTools_SurfaceSet.def("Clear", (void (BinTools_SurfaceSet::*)()) &BinTools_SurfaceSet::Clear, "Clears the content of the set.");
	cls_BinTools_SurfaceSet.def("Add", (Standard_Integer (BinTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &)) &BinTools_SurfaceSet::Add, "Incorporate a new Surface in the set and returns its index.", py::arg("S"));
	cls_BinTools_SurfaceSet.def("Surface", (opencascade::handle<Geom_Surface> (BinTools_SurfaceSet::*)(const Standard_Integer) const ) &BinTools_SurfaceSet::Surface, "Returns the Surface of index <I>.", py::arg("I"));
	cls_BinTools_SurfaceSet.def("Index", (Standard_Integer (BinTools_SurfaceSet::*)(const opencascade::handle<Geom_Surface> &) const ) &BinTools_SurfaceSet::Index, "Returns the index of <L>.", py::arg("S"));
	cls_BinTools_SurfaceSet.def("Write", (void (BinTools_SurfaceSet::*)(Standard_OStream &) const ) &BinTools_SurfaceSet::Write, "Writes the content of me on the stream <OS> in binary format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_SurfaceSet.def("Read", (void (BinTools_SurfaceSet::*)(Standard_IStream &)) &BinTools_SurfaceSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_BinTools_SurfaceSet.def_static("WriteSurface_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &BinTools_SurfaceSet::WriteSurface, "Dumps the surface on the stream in binary format that can be read back.", py::arg("S"), py::arg("OS"));
	cls_BinTools_SurfaceSet.def_static("ReadSurface_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom_Surface> &)) &BinTools_SurfaceSet::ReadSurface, "Reads the surface from the stream. The surface is assumed to have been written with the Write method.", py::arg("IS"), py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_CurveSet.hxx
	py::class_<BinTools_CurveSet, std::unique_ptr<BinTools_CurveSet, Deleter<BinTools_CurveSet>>> cls_BinTools_CurveSet(mod, "BinTools_CurveSet", "Stores a set of Curves from Geom in binary format.");
	cls_BinTools_CurveSet.def(py::init<>());
	cls_BinTools_CurveSet.def("Clear", (void (BinTools_CurveSet::*)()) &BinTools_CurveSet::Clear, "Clears the content of the set.");
	cls_BinTools_CurveSet.def("Add", (Standard_Integer (BinTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &)) &BinTools_CurveSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
	cls_BinTools_CurveSet.def("Curve", (opencascade::handle<Geom_Curve> (BinTools_CurveSet::*)(const Standard_Integer) const ) &BinTools_CurveSet::Curve, "Returns the Curve of index <I>.", py::arg("I"));
	cls_BinTools_CurveSet.def("Index", (Standard_Integer (BinTools_CurveSet::*)(const opencascade::handle<Geom_Curve> &) const ) &BinTools_CurveSet::Index, "Returns the index of <L>.", py::arg("C"));
	cls_BinTools_CurveSet.def("Write", (void (BinTools_CurveSet::*)(Standard_OStream &) const ) &BinTools_CurveSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_CurveSet.def("Read", (void (BinTools_CurveSet::*)(Standard_IStream &)) &BinTools_CurveSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_BinTools_CurveSet.def_static("WriteCurve_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &BinTools_CurveSet::WriteCurve, "Dumps the curve on the stream in binary format that can be read back.", py::arg("C"), py::arg("OS"));
	cls_BinTools_CurveSet.def_static("ReadCurve_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom_Curve> &)) &BinTools_CurveSet::ReadCurve, "Reads the curve from the stream. The curve is assumed to have been written with the Write method", py::arg("IS"), py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_Curve2dSet.hxx
	py::class_<BinTools_Curve2dSet, std::unique_ptr<BinTools_Curve2dSet, Deleter<BinTools_Curve2dSet>>> cls_BinTools_Curve2dSet(mod, "BinTools_Curve2dSet", "Stores a set of Curves from Geom2d in binary format");
	cls_BinTools_Curve2dSet.def(py::init<>());
	cls_BinTools_Curve2dSet.def("Clear", (void (BinTools_Curve2dSet::*)()) &BinTools_Curve2dSet::Clear, "Clears the content of the set.");
	cls_BinTools_Curve2dSet.def("Add", (Standard_Integer (BinTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &)) &BinTools_Curve2dSet::Add, "Incorporate a new Curve in the set and returns its index.", py::arg("C"));
	cls_BinTools_Curve2dSet.def("Curve2d", (opencascade::handle<Geom2d_Curve> (BinTools_Curve2dSet::*)(const Standard_Integer) const ) &BinTools_Curve2dSet::Curve2d, "Returns the Curve of index <I>.", py::arg("I"));
	cls_BinTools_Curve2dSet.def("Index", (Standard_Integer (BinTools_Curve2dSet::*)(const opencascade::handle<Geom2d_Curve> &) const ) &BinTools_Curve2dSet::Index, "Returns the index of <L>.", py::arg("C"));
	// FIXME cls_BinTools_Curve2dSet.def("Dump", (void (BinTools_Curve2dSet::*)(Standard_OStream &) const ) &BinTools_Curve2dSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_BinTools_Curve2dSet.def("Write", (void (BinTools_Curve2dSet::*)(Standard_OStream &) const ) &BinTools_Curve2dSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_Curve2dSet.def("Read", (void (BinTools_Curve2dSet::*)(Standard_IStream &)) &BinTools_Curve2dSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_BinTools_Curve2dSet.def_static("WriteCurve2d_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &BinTools_Curve2dSet::WriteCurve2d, "Dumps the curve on the binary stream, that can be read back.", py::arg("C"), py::arg("OS"));
	cls_BinTools_Curve2dSet.def_static("ReadCurve2d_", (Standard_IStream & (*)(Standard_IStream &, opencascade::handle<Geom2d_Curve> &)) &BinTools_Curve2dSet::ReadCurve2d, "Reads the curve from the stream. The curve is assumed to have been written with the Write method.", py::arg("IS"), py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_ShapeSet.hxx
	py::class_<BinTools_ShapeSet, std::unique_ptr<BinTools_ShapeSet, Deleter<BinTools_ShapeSet>>> cls_BinTools_ShapeSet(mod, "BinTools_ShapeSet", "Writes topology in OStream in binary format");
	cls_BinTools_ShapeSet.def(py::init<>());
	cls_BinTools_ShapeSet.def(py::init<const Standard_Boolean>(), py::arg("isWithTriangles"));
	cls_BinTools_ShapeSet.def("IsWithTriangles", (Standard_Boolean (BinTools_ShapeSet::*)() const ) &BinTools_ShapeSet::IsWithTriangles, "Return true if shape should be stored with triangles.");
	cls_BinTools_ShapeSet.def("SetWithTriangles", (void (BinTools_ShapeSet::*)(const Standard_Boolean)) &BinTools_ShapeSet::SetWithTriangles, "Define if shape will be stored with triangles. Ignored (always written) if face defines only triangulation (no surface).", py::arg("isWithTriangles"));
	cls_BinTools_ShapeSet.def("SetFormatNb", (void (BinTools_ShapeSet::*)(const Standard_Integer)) &BinTools_ShapeSet::SetFormatNb, "None", py::arg("theFormatNb"));
	cls_BinTools_ShapeSet.def("FormatNb", (Standard_Integer (BinTools_ShapeSet::*)() const ) &BinTools_ShapeSet::FormatNb, "two formats available for the moment: First: does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points. On reading format is recognized from Version string.");
	cls_BinTools_ShapeSet.def("Clear", (void (BinTools_ShapeSet::*)()) &BinTools_ShapeSet::Clear, "Clears the content of the set.");
	cls_BinTools_ShapeSet.def("Add", (Standard_Integer (BinTools_ShapeSet::*)(const TopoDS_Shape &)) &BinTools_ShapeSet::Add, "Stores <S> and its sub-shape. Returns the index of <S>. The method AddGeometry is called on each sub-shape.", py::arg("S"));
	cls_BinTools_ShapeSet.def("Shape", (const TopoDS_Shape & (BinTools_ShapeSet::*)(const Standard_Integer) const ) &BinTools_ShapeSet::Shape, "Returns the sub-shape of index <I>.", py::arg("I"));
	cls_BinTools_ShapeSet.def("Index", (Standard_Integer (BinTools_ShapeSet::*)(const TopoDS_Shape &) const ) &BinTools_ShapeSet::Index, "Returns the index of <S>.", py::arg("S"));
	cls_BinTools_ShapeSet.def("Locations", (const BinTools_LocationSet & (BinTools_ShapeSet::*)() const ) &BinTools_ShapeSet::Locations, "None");
	cls_BinTools_ShapeSet.def("ChangeLocations", (BinTools_LocationSet & (BinTools_ShapeSet::*)()) &BinTools_ShapeSet::ChangeLocations, "None");
	cls_BinTools_ShapeSet.def("NbShapes", (Standard_Integer (BinTools_ShapeSet::*)() const ) &BinTools_ShapeSet::NbShapes, "Returns number of shapes read from file.");
	cls_BinTools_ShapeSet.def("Write", (void (BinTools_ShapeSet::*)(Standard_OStream &) const ) &BinTools_ShapeSet::Write, "Writes the content of me on the stream <OS> in binary format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_ShapeSet.def("Read", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::Read, "Reads the content of me from the binary stream <IS>. me is first cleared.", py::arg("IS"));
	cls_BinTools_ShapeSet.def("Write", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &BinTools_ShapeSet::Write, "Writes on <OS> the shape <S>. Writes the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
	cls_BinTools_ShapeSet.def("WriteGeometry", (void (BinTools_ShapeSet::*)(Standard_OStream &) const ) &BinTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a binary format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_ShapeSet.def("ReadGeometry", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
	cls_BinTools_ShapeSet.def("Read", (void (BinTools_ShapeSet::*)(TopoDS_Shape &, Standard_IStream &, const Standard_Integer) const ) &BinTools_ShapeSet::Read, "Reads from <IS> a shape and returns it in S. <NbShapes> is the number of tshapes in the set.", py::arg("S"), py::arg("IS"), py::arg("NbShapes"));
	cls_BinTools_ShapeSet.def("WriteGeometry", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &BinTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a binary format that can be read back by Read.", py::arg("S"), py::arg("OS"));
	cls_BinTools_ShapeSet.def("ReadGeometry", (void (BinTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &BinTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
	cls_BinTools_ShapeSet.def("AddGeometry", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &)) &BinTools_ShapeSet::AddGeometry, "Stores the goemetry of <S>.", py::arg("S"));
	cls_BinTools_ShapeSet.def("AddShapes", (void (BinTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &BinTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>.", py::arg("S1"), py::arg("S2"));
	cls_BinTools_ShapeSet.def("ReadPolygon3D", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadPolygon3D, "Reads the 3d polygons of me from the stream <IS>.", py::arg("IS"));
	cls_BinTools_ShapeSet.def("WritePolygon3D", (void (BinTools_ShapeSet::*)(Standard_OStream &) const ) &BinTools_ShapeSet::WritePolygon3D, "Writes the 3d polygons on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_ShapeSet.def("ReadTriangulation", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadTriangulation, "Reads the triangulation of me from the stream <IS>.", py::arg("IS"));
	cls_BinTools_ShapeSet.def("WriteTriangulation", (void (BinTools_ShapeSet::*)(Standard_OStream &) const ) &BinTools_ShapeSet::WriteTriangulation, "Writes the triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_BinTools_ShapeSet.def("ReadPolygonOnTriangulation", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadPolygonOnTriangulation, "Reads the polygons on triangulation of me from the stream <IS>.", py::arg("IS"));
	cls_BinTools_ShapeSet.def("WritePolygonOnTriangulation", (void (BinTools_ShapeSet::*)(Standard_OStream &) const ) &BinTools_ShapeSet::WritePolygonOnTriangulation, "Writes the polygons on triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools.hxx
	py::class_<BinTools, std::unique_ptr<BinTools, Deleter<BinTools>>> cls_BinTools(mod, "BinTools", "Tool to keep shapes in binary format");
	cls_BinTools.def(py::init<>());
	cls_BinTools.def_static("PutReal_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Real)) &BinTools::PutReal, "None", py::arg("OS"), py::arg("theValue"));
	cls_BinTools.def_static("PutInteger_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Integer)) &BinTools::PutInteger, "None", py::arg("OS"), py::arg("theValue"));
	cls_BinTools.def_static("PutBool_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Boolean)) &BinTools::PutBool, "None", py::arg("OS"), py::arg("theValue"));
	cls_BinTools.def_static("PutExtChar_", (Standard_OStream & (*)(Standard_OStream &, const Standard_ExtCharacter)) &BinTools::PutExtChar, "None", py::arg("OS"), py::arg("theValue"));
	cls_BinTools.def_static("GetReal_", [](Standard_IStream & IS, Standard_Real & theValue){ Standard_IStream & rv = BinTools::GetReal(IS, theValue); return std::tuple<Standard_IStream &, Standard_Real &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
	cls_BinTools.def_static("GetInteger_", [](Standard_IStream & IS, Standard_Integer & theValue){ Standard_IStream & rv = BinTools::GetInteger(IS, theValue); return std::tuple<Standard_IStream &, Standard_Integer &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
	cls_BinTools.def_static("GetBool_", [](Standard_IStream & IS, Standard_Boolean & theValue){ Standard_IStream & rv = BinTools::GetBool(IS, theValue); return std::tuple<Standard_IStream &, Standard_Boolean &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
	// FIXME cls_BinTools.def_static("GetExtChar_", (Standard_IStream & (*)(Standard_IStream &, Standard_ExtCharacter &)) &BinTools::GetExtChar, "None", py::arg("IS"), py::arg("theValue"));
	cls_BinTools.def_static("Write_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &BinTools::Write, "Writes <theShape> on <theStream> in binary format.", py::arg("theShape"), py::arg("theStream"));
	cls_BinTools.def_static("Read_", (void (*)(TopoDS_Shape &, Standard_IStream &)) &BinTools::Read, "Reads a shape from <theStream> and returns it in <theShape>.", py::arg("theShape"), py::arg("theStream"));
	cls_BinTools.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString)) &BinTools::Write, "Writes <theShape> in <theFile>.", py::arg("theShape"), py::arg("theFile"));
	cls_BinTools.def_static("Read_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_CString)) &BinTools::Read, "Reads a shape from <theFile> and returns it in <theShape>.", py::arg("theShape"), py::arg("theFile"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTools_LocationSetPtr.hxx

}
