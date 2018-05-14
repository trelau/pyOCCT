# Generate unit test file for Graphic3d_RenderingParams

header = '''# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import unittest

from OCCT.Graphic3d import (Graphic3d_RenderingParams,
        Graphic3d_RM_RASTERIZATION, Graphic3d_RM_RAYTRACING,
        Graphic3d_RTM_BLEND_UNORDERED, Graphic3d_RTM_BLEND_OIT,
        Graphic3d_StereoMode_QuadBuffer, Graphic3d_StereoMode_SideBySide,
        Graphic3d_ToneMappingMethod_Disabled,
        Graphic3d_ToneMappingMethod_Filmic)


class TestGraphic3dRenderingParamsDataFields(unittest.TestCase):
    """
    Test for Data Fields of Graphic3d_RenderingParams
    """
'''

footer = '''
if __name__ == '__main__':
    unittest.main()
'''

meth = '''
    def test_{0}(self):
        """
        Test {0} data field.
        """
        p = Graphic3d_RenderingParams()

        val = p.{0}
        self.{3}(val, {1}, 'incorrect default')

        p.Method = {2}
        val = p.{0}
        self.{3}(val, {2}, 'set/get error')
'''

params = [
    ('AdaptiveScreenSampling', False, True),
    ('AnaglyphFilter',
         'Graphic3d_RenderingParams.Anaglyph.Anaglyph_RedCyan_Optimized',
         'Graphic3d_RenderingParams.Anaglyph.Anaglyph_GreenMagenta_Simple'),
#    ('AnaglyphLeft', 'Graphic3d_Mat4', 'Graphic3d_Mat4'),
#    ('AnaglyphRight', 'Graphic3d_Mat4', 'Graphic3d_Mat4'),
    ('CameraApertureRadius', 0.0, 1.0),
    ('CameraFocalPlaneDist', 1.0, 2.0),
    ('CoherentPathTracingMode', False, True),
    ('Exposure', 0.0, 1.0),
    ('IsAntialiasingEnabled', False, True),
    ('IsGlobalIlluminationEnabled', False, True),
    ('IsReflectionEnabled', False, True),
    ('IsShadowEnabled', True, False),
    ('IsTransparentShadowEnabled', False, True),
    ('Method', 'Graphic3d_RM_RASTERIZATION', 'Graphic3d_RM_RAYTRACING'),
    ('NbMsaaSamples', 0, 2),
    ('NbRayTracingTiles', 0, 2),
    ('OitDepthFactor', 0.0, 0.5),
    ('RadianceClampingValue', 0.0, 0.5),
    ('RaytracingDepth', 3, 4),
    ('RebuildRayTracingShaders', False, True),
    ('RenderResolutionScale', 1.0, 2.0),
    ('Resolution', 72, 96),
    ('SamplesPerPixel', 1, 2),
    ('ShowSamplingTiles', False, True),
    ('StereoMode', 'Graphic3d_StereoMode_QuadBuffer',
        'Graphic3d_StereoMode_SideBySide'),
    ('THE_DEFAULT_DEPTH', 3, 4),
    ('THE_DEFAULT_RESOLUTION', 72, 96),
    ('ToneMappingMethod', 'Graphic3d_ToneMappingMethod_Disabled',
        'Graphic3d_ToneMappingMethod_Filmic'),
    ('ToReverseStereo', False, True),
    ('TransparencyMethod', 'Graphic3d_RTM_BLEND_UNORDERED',
        'Graphic3d_RTM_BLEND_OIT'),
    ('TwoSidedBsdfModels', False, True),
    ('UseEnvironmentMapBackground', False, True),
    ('WhitePoint', 1.0, 2.0),
    ]


def makeTests():
    with open('test_graphic3d_rendering_params.py', 'w') as out:
        out.write(header)
        for p in params:
            if isinstance(p[1], float):
                a = 'assertAlmostEqual'
            else:
                a = 'assertEqual'
            m = meth.format(p[0], p[1], p[2], a)
            out.write(m)
        out.write(footer)


if __name__ == "__main__":
    makeTests()
