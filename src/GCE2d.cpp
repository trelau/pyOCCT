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
#include <gce_ErrorType.hxx>
#include <GCE2d_Root.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <GCE2d_MakeArcOfCircle.hxx>
#include <gp_Elips2d.hxx>
#include <GCE2d_MakeArcOfEllipse.hxx>
#include <gp_Hypr2d.hxx>
#include <GCE2d_MakeArcOfHyperbola.hxx>
#include <gp_Parab2d.hxx>
#include <GCE2d_MakeArcOfParabola.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Ax22d.hxx>
#include <Geom2d_Circle.hxx>
#include <GCE2d_MakeCircle.hxx>
#include <Geom2d_Ellipse.hxx>
#include <GCE2d_MakeEllipse.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <GCE2d_MakeHyperbola.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Dir2d.hxx>
#include <Geom2d_Line.hxx>
#include <GCE2d_MakeLine.hxx>
#include <Geom2d_Transformation.hxx>
#include <GCE2d_MakeMirror.hxx>
#include <Geom2d_Parabola.hxx>
#include <GCE2d_MakeParabola.hxx>
#include <GCE2d_MakeRotation.hxx>
#include <GCE2d_MakeScale.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <GCE2d_MakeTranslation.hxx>

PYBIND11_MODULE(GCE2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gce");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_Root.hxx
	py::class_<GCE2d_Root, std::unique_ptr<GCE2d_Root, Deleter<GCE2d_Root>>> cls_GCE2d_Root(mod, "GCE2d_Root", "This class implements the common services for all classes of gce which report error.");
	cls_GCE2d_Root.def(py::init<>());
	cls_GCE2d_Root.def("IsDone", (Standard_Boolean (GCE2d_Root::*)() const ) &GCE2d_Root::IsDone, "Returns true if the construction is successful.");
	cls_GCE2d_Root.def("Status", (gce_ErrorType (GCE2d_Root::*)() const ) &GCE2d_Root::Status, "Returns the status of the construction - gce_Done, if the construction is successful, or - another value of the gce_ErrorType enumeration indicating why the construction failed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeArcOfCircle.hxx
	py::class_<GCE2d_MakeArcOfCircle, std::unique_ptr<GCE2d_MakeArcOfCircle, Deleter<GCE2d_MakeArcOfCircle>>, GCE2d_Root> cls_GCE2d_MakeArcOfCircle(mod, "GCE2d_MakeArcOfCircle", "Implements construction algorithms for an arc of circle in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeArcOfCircle object provides a framework for: - defining the construction of the arc of circle, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of circle.");
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Circ"), py::arg("Alpha1"), py::arg("Alpha2"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Circ"), py::arg("P"), py::arg("Alpha"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Circ"), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Circ"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Pnt2d &, const gp_Vec2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("V"), py::arg("P2"));
	cls_GCE2d_MakeArcOfCircle.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeArcOfCircle::*)() const ) &GCE2d_MakeArcOfCircle::Value, "Returns the constructed arc of circle. Exceptions StdFail_NotDone if no arc of circle is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeArcOfEllipse.hxx
	py::class_<GCE2d_MakeArcOfEllipse, std::unique_ptr<GCE2d_MakeArcOfEllipse, Deleter<GCE2d_MakeArcOfEllipse>>, GCE2d_Root> cls_GCE2d_MakeArcOfEllipse(mod, "GCE2d_MakeArcOfEllipse", "Implements construction algorithms for an arc of ellipse in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeArcOfEllipse object provides a framework for: - defining the construction of the arc of ellipse, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of ellipse.");
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const Standard_Real, const Standard_Real>(), py::arg("Elips"), py::arg("Alpha1"), py::arg("Alpha2"));
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Elips"), py::arg("P"), py::arg("Alpha"));
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Elips"), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeArcOfEllipse.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Elips"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfEllipse.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeArcOfEllipse::*)() const ) &GCE2d_MakeArcOfEllipse::Value, "Returns the constructed arc of ellipse.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeArcOfHyperbola.hxx
	py::class_<GCE2d_MakeArcOfHyperbola, std::unique_ptr<GCE2d_MakeArcOfHyperbola, Deleter<GCE2d_MakeArcOfHyperbola>>, GCE2d_Root> cls_GCE2d_MakeArcOfHyperbola(mod, "GCE2d_MakeArcOfHyperbola", "Implements construction algorithms for an arc of hyperbola in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeArcOfHyperbola object provides a framework for: - defining the construction of the arc of hyperbola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of hyperbola.");
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real>(), py::arg("Hypr"), py::arg("Alpha1"), py::arg("Alpha2"));
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Hypr"), py::arg("P"), py::arg("Alpha"));
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Hypr"), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeArcOfHyperbola.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfHyperbola.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeArcOfHyperbola::*)() const ) &GCE2d_MakeArcOfHyperbola::Value, "Returns the constructed arc of hyperbola.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeArcOfParabola.hxx
	py::class_<GCE2d_MakeArcOfParabola, std::unique_ptr<GCE2d_MakeArcOfParabola, Deleter<GCE2d_MakeArcOfParabola>>, GCE2d_Root> cls_GCE2d_MakeArcOfParabola(mod, "GCE2d_MakeArcOfParabola", "Implements construction algorithms for an arc of parabola in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeArcOfParabola object provides a framework for: - defining the construction of the arc of parabola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of parabola.");
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real>(), py::arg("Parab"), py::arg("Alpha1"), py::arg("Alpha2"));
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Parab"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Parab"), py::arg("P"), py::arg("Alpha"));
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Parab"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Parab"), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeArcOfParabola.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Parab"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
	cls_GCE2d_MakeArcOfParabola.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeArcOfParabola::*)() const ) &GCE2d_MakeArcOfParabola::Value, "Returns the constructed arc of parabola.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeCircle.hxx
	py::class_<GCE2d_MakeCircle, std::unique_ptr<GCE2d_MakeCircle, Deleter<GCE2d_MakeCircle>>, GCE2d_Root> cls_GCE2d_MakeCircle(mod, "GCE2d_MakeCircle", "This class implements the following algorithms used to create Circle from Geom2d.");
	cls_GCE2d_MakeCircle.def(py::init<const gp_Circ2d &>(), py::arg("C"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("A"), py::arg("Radius"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("A"), py::arg("Radius"), py::arg("Sense"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("A"), py::arg("Radius"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Circ2d &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &>(), py::arg("Circ"), py::arg("Point"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("P"), py::arg("Radius"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("P"), py::arg("Radius"), py::arg("Sense"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Center"), py::arg("Point"));
	cls_GCE2d_MakeCircle.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Center"), py::arg("Point"), py::arg("Sense"));
	cls_GCE2d_MakeCircle.def("Value", (const opencascade::handle<Geom2d_Circle> & (GCE2d_MakeCircle::*)() const ) &GCE2d_MakeCircle::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeEllipse.hxx
	py::class_<GCE2d_MakeEllipse, std::unique_ptr<GCE2d_MakeEllipse, Deleter<GCE2d_MakeEllipse>>, GCE2d_Root> cls_GCE2d_MakeEllipse(mod, "GCE2d_MakeEllipse", "This class implements the following algorithms used to create Ellipse from Geom2d. * Create an Ellipse from two apex and the center. Defines an ellipse in 2D space. The parametrization range is [0,2*PI]. The ellipse is a closed and periodic curve. The center of the ellipse is the 'Location' point of its axis placement 'XAxis'. The 'XAxis' of the ellipse defines the origin of the parametrization, it is the major axis of the ellipse. The YAxis is the minor axis of the ellipse.");
	cls_GCE2d_MakeEllipse.def(py::init<const gp_Elips2d &>(), py::arg("E"));
	cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
	cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
	cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
	cls_GCE2d_MakeEllipse.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));
	cls_GCE2d_MakeEllipse.def("Value", (const opencascade::handle<Geom2d_Ellipse> & (GCE2d_MakeEllipse::*)() const ) &GCE2d_MakeEllipse::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeHyperbola.hxx
	py::class_<GCE2d_MakeHyperbola, std::unique_ptr<GCE2d_MakeHyperbola, Deleter<GCE2d_MakeHyperbola>>, GCE2d_Root> cls_GCE2d_MakeHyperbola(mod, "GCE2d_MakeHyperbola", "This class implements the following algorithms used to create Hyperbola from Geom2d. * Create an Hyperbola from two apex and the center. Defines the main branch of an hyperbola. The parameterization range is ]-infinite,+infinite[ It is possible to get the other branch and the two conjugate branches of the main branch.");
	cls_GCE2d_MakeHyperbola.def(py::init<const gp_Hypr2d &>(), py::arg("H"));
	cls_GCE2d_MakeHyperbola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
	cls_GCE2d_MakeHyperbola.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
	cls_GCE2d_MakeHyperbola.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));
	cls_GCE2d_MakeHyperbola.def("Value", (const opencascade::handle<Geom2d_Hyperbola> & (GCE2d_MakeHyperbola::*)() const ) &GCE2d_MakeHyperbola::Value, "Returns the constructed hyperbola. Exceptions: StdFail_NotDone if no hyperbola is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeLine.hxx
	py::class_<GCE2d_MakeLine, std::unique_ptr<GCE2d_MakeLine, Deleter<GCE2d_MakeLine>>, GCE2d_Root> cls_GCE2d_MakeLine(mod, "GCE2d_MakeLine", "This class implements the following algorithms used to create a Line from Geom2d. * Create a Line parallel to another and passing through a point. * Create a Line passing through 2 points.");
	cls_GCE2d_MakeLine.def(py::init<const gp_Ax2d &>(), py::arg("A"));
	cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &>(), py::arg("L"));
	cls_GCE2d_MakeLine.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
	cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &, const gp_Pnt2d &>(), py::arg("Lin"), py::arg("Point"));
	cls_GCE2d_MakeLine.def(py::init<const gp_Lin2d &, const Standard_Real>(), py::arg("Lin"), py::arg("Dist"));
	cls_GCE2d_MakeLine.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeLine.def("Value", (const opencascade::handle<Geom2d_Line> & (GCE2d_MakeLine::*)() const ) &GCE2d_MakeLine::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeMirror.hxx
	py::class_<GCE2d_MakeMirror, std::unique_ptr<GCE2d_MakeMirror, Deleter<GCE2d_MakeMirror>>> cls_GCE2d_MakeMirror(mod, "GCE2d_MakeMirror", "This class implements elementary construction algorithms for a symmetrical transformation in 2D space about a point or axis. The result is a Geom2d_Transformation transformation. A MakeMirror object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");
	cls_GCE2d_MakeMirror.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));
	cls_GCE2d_MakeMirror.def(py::init<const gp_Ax2d &>(), py::arg("Axis"));
	cls_GCE2d_MakeMirror.def(py::init<const gp_Lin2d &>(), py::arg("Line"));
	cls_GCE2d_MakeMirror.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("Point"), py::arg("Direc"));
	cls_GCE2d_MakeMirror.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeMirror::*)() const ) &GCE2d_MakeMirror::Value, "Returns the constructed transformation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeParabola.hxx
	py::class_<GCE2d_MakeParabola, std::unique_ptr<GCE2d_MakeParabola, Deleter<GCE2d_MakeParabola>>, GCE2d_Root> cls_GCE2d_MakeParabola(mod, "GCE2d_MakeParabola", "This class implements the following algorithms used to create Parabola from Geom2d. * Create an Parabola from two apex and the center. Defines the parabola in the parameterization range : ]-infinite,+infinite[ The vertex of the parabola is the 'Location' point of the local coordinate system 'XAxis' of the parabola. The 'XAxis' of the parabola is its axis of symmetry. The 'Xaxis' is oriented from the vertex of the parabola to the Focus of the parabola. The equation of the parabola in the local coordinate system is Y**2 = (2*P) * X P is the distance between the focus and the directrix of the parabola called Parameter). The focal length F = P/2 is the distance between the vertex and the focus of the parabola.");
	cls_GCE2d_MakeParabola.def(py::init<const gp_Parab2d &>(), py::arg("Prb"));
	cls_GCE2d_MakeParabola.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Focal"));
	cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("MirrorAxis"), py::arg("Focal"), py::arg("Sense"));
	cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("D"), py::arg("F"));
	cls_GCE2d_MakeParabola.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("D"), py::arg("F"), py::arg("Sense"));
	cls_GCE2d_MakeParabola.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("O"));
	cls_GCE2d_MakeParabola.def("Value", (const opencascade::handle<Geom2d_Parabola> & (GCE2d_MakeParabola::*)() const ) &GCE2d_MakeParabola::Value, "Returns the constructed parabola. Exceptions StdFail_NotDone if no parabola is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeRotation.hxx
	py::class_<GCE2d_MakeRotation, std::unique_ptr<GCE2d_MakeRotation, Deleter<GCE2d_MakeRotation>>> cls_GCE2d_MakeRotation(mod, "GCE2d_MakeRotation", "This class implements an elementary construction algorithm for a rotation in 2D space. The result is a Geom2d_Transformation transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");
	cls_GCE2d_MakeRotation.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Angle"));
	cls_GCE2d_MakeRotation.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeRotation::*)() const ) &GCE2d_MakeRotation::Value, "Returns the constructed transformation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeScale.hxx
	py::class_<GCE2d_MakeScale, std::unique_ptr<GCE2d_MakeScale, Deleter<GCE2d_MakeScale>>> cls_GCE2d_MakeScale(mod, "GCE2d_MakeScale", "This class implements an elementary construction algorithm for a scaling transformation in 2D space. The result is a Geom2d_Transformation transformation. A MakeScale object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");
	cls_GCE2d_MakeScale.def(py::init<const gp_Pnt2d &, const Standard_Real>(), py::arg("Point"), py::arg("Scale"));
	cls_GCE2d_MakeScale.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeScale::*)() const ) &GCE2d_MakeScale::Value, "Returns the constructed transformation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeSegment.hxx
	py::class_<GCE2d_MakeSegment, std::unique_ptr<GCE2d_MakeSegment, Deleter<GCE2d_MakeSegment>>, GCE2d_Root> cls_GCE2d_MakeSegment(mod, "GCE2d_MakeSegment", "Implements construction algorithms for a line segment in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeSegment object provides a framework for: - defining the construction of the line segment, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed line segment.");
	cls_GCE2d_MakeSegment.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeSegment.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("V"), py::arg("P2"));
	cls_GCE2d_MakeSegment.def(py::init<const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("U1"), py::arg("U2"));
	cls_GCE2d_MakeSegment.def(py::init<const gp_Lin2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Line"), py::arg("Point"), py::arg("Ulast"));
	cls_GCE2d_MakeSegment.def(py::init<const gp_Lin2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Line"), py::arg("P1"), py::arg("P2"));
	cls_GCE2d_MakeSegment.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeSegment::*)() const ) &GCE2d_MakeSegment::Value, "Returns the constructed line segment. Exceptions StdFail_NotDone if no line segment is constructed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GCE2d_MakeTranslation.hxx
	py::class_<GCE2d_MakeTranslation, std::unique_ptr<GCE2d_MakeTranslation, Deleter<GCE2d_MakeTranslation>>> cls_GCE2d_MakeTranslation(mod, "GCE2d_MakeTranslation", "This class implements elementary construction algorithms for a translation in 2D space. The result is a Geom2d_Transformation transformation. A MakeTranslation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");
	cls_GCE2d_MakeTranslation.def(py::init<const gp_Vec2d &>(), py::arg("Vect"));
	cls_GCE2d_MakeTranslation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Point1"), py::arg("Point2"));
	cls_GCE2d_MakeTranslation.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeTranslation::*)() const ) &GCE2d_MakeTranslation::Value, "Returns the constructed transformation.");


}
