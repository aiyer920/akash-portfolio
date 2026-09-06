---
layout: default
title: About
permalink: /about/
---

<div class="hero-section about-hero">
    <div class="container">
        <div class="about-hero-grid">
            <div class="about-hero-intro">
                <h1>About Me</h1>
                <p>I'm Akash Iyer, an aspiring robotics engineer with a keen interest in robot mechanics, design, control systems.</p>
            </div>

            <div class="resume-preview">
                <object
                    data="{{ '/assets/resume/Akash-Iyer-Resume.pdf' | relative_url }}"
                    type="application/pdf"
                    title="Akash Iyer's resume"
                >
                    <p>
                        Your browser cannot display the embedded résumé.
                        <a href="{{ '/assets/resume/Akash-Iyer-Resume.pdf' | relative_url }}" target="_blank">Open the PDF instead.</a>
                    </p>
                </object>
                <a class="resume-open-link" href="{{ '/assets/resume/Akash-Iyer-Resume.pdf' | relative_url }}" target="_blank">
                    <i class="fas fa-file-pdf"></i> Open Résumé PDF
                </a>
            </div>
        </div>
    </div>
</div>

<div class="about-content">
    <div class="container">
        
        <section class="about-section">
            <h2>My Background</h2>
            <p>I'm an M.S. student in Robotics at the Georgia Institute of Technology, with a B.S. in Mechanical Engineering from the University of Maryland, College Park. </p>
            
            <p>Through research, internships, and coursework, I've developed a passion for robotics and engineering while building experience across mechanical design, manufacturing, control systems, and deep learning. My robotics work has spanned quadrupedal and humanoid robots, underwater robotics, and a variety of mechatronic systems. </p>

            <p>Outside of engineering, I enjoy table tennis, soccer, and video games.</p>

            <p>This portfolio highlights my projects, professional experiences, and education. Feel free to reach out, I'm always interested in connecting and discussing new ideas and opportunities.</p>
        </section>

        <section class="about-section">
            <h2>Education</h2>
            <div class="features-list">
                <div class="feature-item">
                    <h3><i class="fas fa-graduation-cap"></i> Georgia Institute of Technology</h3>
                    <p class="feature-meta">M.S. in Robotics · Atlanta, GA</p>
                    <p>August 2025 – May 2027</p>
                </div>

                <div class="feature-item">
                    <h3><i class="fas fa-graduation-cap"></i> University of Maryland</h3>
                    <p class="feature-meta">B.S. in Mechanical Engineering · College Park, MD</p>
                    <p>August 2022 – May 2025</p>
                </div>
            </div>
        </section>

        <section class="about-section">
            <h2>Experience</h2>
            <div class="features-list" id="experience-grid">
                <div class="feature-item">
                    <h3><i class="fas fa-briefcase"></i> Mechanical Systems and Project Engineering Intern</h3>
                    <p class="feature-meta">Boeing · Ridley Park, PA · May–August 2025 and May–August 2026</p>
                    <ul class="feature-details">
                        <li>Created CATIA CAD models of CH-47 transmission-system components to evaluate capability improvements.</li>
                        <li>Helped test mechanical components and resolve issues with aircraft fuel systems.</li>
                        <li>Prepared engineering change proposals to meet customer requirements and document engineering changes.</li>
                    </ul>
                </div>

                <div class="feature-item">
                    <h3><i class="fas fa-chalkboard-teacher"></i> Mechanical Engineering Undergraduate Teaching Fellow</h3>
                    <p class="feature-meta">University of Maryland · College Park, MD · August 2024–May 2025</p>
                    <ul class="feature-details">
                        <li>Prepared and conducted midterm and final exam reviews for ENME 382: Materials Engineering.</li>
                        <li>Developed rubrics and graded assignments in coordination with other teaching fellows.</li>
                        <li>Taught and assisted students with assignments and exam preparation during office hours.</li>
                    </ul>
                </div>

                <div class="feature-item">
                    <h3><i class="fas fa-flask"></i> Undergraduate Researcher</h3>
                    <p class="feature-meta">University of Maryland · College Park, MD · January 2024–May 2025</p>
                    <ul class="feature-details">
                        <li>Developed and iterated on CAD models for a tuna-inspired autonomous underwater vehicle prototype.</li>
                        <li>Manufactured and integrated components using 3D printing, casting, and manual methods.</li>
                    </ul>
                </div>

                <div class="feature-item experience-extra is-hidden">
                    <h3><i class="fas fa-cogs"></i> Applications Engineering Intern</h3>
                    <p class="feature-meta">Henkel · Bridgewater, NJ · June–August 2024</p>
                    <ul class="feature-details">
                        <li>Evaluated manufacturing ideas to develop material formulations and production techniques.</li>
                        <li>Planned and executed tests to ensure new formulations could be produced across Henkel's manufacturing network.</li>
                    </ul>
                </div>

                <div class="feature-item experience-extra is-hidden">
                    <h3><i class="fas fa-solar-panel"></i> Engineering Intern</h3>
                    <p class="feature-meta">Gaia Energy Research Institute · Alexandria, VA · August 2023–June 2024</p>
                    <ul class="feature-details">
                        <li>Applied physics, thermodynamics, and renewable-energy principles to support design development.</li>
                        <li>Developed computer models analyzing the physics, economics, and environmental impact of renewable energy.</li>
                    </ul>
                </div>
            </div>

            <div class="experience-toggle-wrap">
                <button
                    id="experience-toggle"
                    class="btn-secondary experience-toggle"
                    type="button"
                    aria-expanded="false"
                    aria-controls="experience-grid"
                >
                    <i class="fas fa-chevron-down" aria-hidden="true"></i>
                    <span>Show More</span>
                </button>
            </div>
        </section>

        <section class="about-section">
            <h2>Contact Me</h2>
            <p>I'm always interested in connecting and discussing robotics, engineering, and new opportunities.</p>
            <div class="contact-links">
                <a href="https://www.linkedin.com/in/akash-iyer/" class="btn-primary" target="_blank" rel="noopener noreferrer">
                    <i class="fab fa-linkedin"></i> LinkedIn
                </a>
                <a href="mailto:akashiyer2022@gmail.com" class="btn-secondary">
                    <i class="fas fa-envelope"></i> akashiyer2022@gmail.com
                </a>
                <a href="tel:+19086363197" class="btn-secondary">
                    <i class="fas fa-phone"></i> 908-636-3197
                </a>
            </div>
        </section>

    </div>
</div>

<style>
.about-hero {
    padding: var(--spacing-3xl) 0;
    background: var(--background-color);
    border-bottom: 1px solid var(--border-color);
}

.about-hero-grid {
    display: grid;
    grid-template-columns: minmax(0, 0.8fr) minmax(440px, 1.2fr);
    align-items: center;
    gap: var(--spacing-3xl);
}

.about-hero-intro h1 {
    color: var(--text-primary);
    font-size: var(--font-size-3xl);
    letter-spacing: -0.02em;
}

.about-hero-intro p {
    max-width: 600px;
    color: var(--text-secondary);
    font-weight: 300;
    line-height: var(--line-height-relaxed);
    opacity: 0.7;
}

.resume-preview {
    overflow: hidden;
    background: var(--surface-color);
    border: 1px solid var(--border-color);
    border-radius: var(--radius-lg);
    box-shadow: 0 12px 30px var(--shadow-color);
}

.resume-preview object {
    display: block;
    width: 100%;
    height: 680px;
    border: 0;
}

.resume-open-link {
    display: flex;
    align-items: center;
    justify-content: center;
    gap: var(--spacing-sm);
    padding: var(--spacing-md);
    color: var(--primary-color);
    border-top: 1px solid var(--border-color);
    font-weight: var(--font-weight-medium);
    text-decoration: none;
}

.resume-open-link:hover {
    color: var(--accent-color);
}

.about-content {
    padding: var(--spacing-2xl) 0;
}

.about-section {
    margin-bottom: var(--spacing-3xl);
}

.about-section h2 {
    color: var(--text-primary);
    margin-bottom: var(--spacing-lg);
    padding-bottom: var(--spacing-sm);
    border-bottom: 1px solid var(--border-color);
    font-size: var(--font-size-2xl);
    letter-spacing: -0.01em;
}

.features-list {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
    gap: var(--spacing-xl);
    margin-top: var(--spacing-lg);
}

#experience-grid {
    grid-template-columns: 1fr;
}

.feature-item {
    padding: var(--spacing-lg);
    background-color: var(--surface-color);
    border-radius: var(--radius-sm);
    border: none;
    box-shadow: 0 4px 20px var(--shadow-color);
    transition: transform var(--transition-normal), box-shadow var(--transition-normal);
}

.feature-item:hover {
    transform: translateY(-4px);
    box-shadow: 0 12px 30px var(--shadow-hover);
}

.feature-item h3 {
    display: flex;
    align-items: center;
    gap: var(--spacing-sm);
    color: var(--text-primary);
    margin-bottom: var(--spacing-md);
}

.feature-item h3 i {
    color: var(--primary-color);
    font-size: var(--font-size-lg);
}

.feature-meta {
    color: var(--primary-color);
    font-weight: var(--font-weight-medium);
    line-height: var(--line-height-relaxed);
}

.feature-details {
    margin: var(--spacing-md) 0 0;
    padding-left: var(--spacing-lg);
}

.feature-details li {
    margin-bottom: var(--spacing-sm);
    color: var(--text-secondary);
    line-height: var(--line-height-relaxed);
}

.experience-extra.is-hidden {
    display: none;
}

.experience-toggle-wrap {
    display: flex;
    justify-content: center;
    margin-top: var(--spacing-xl);
}

.experience-toggle {
    font-family: inherit;
}

.contact-links {
    display: flex;
    flex-wrap: wrap;
    gap: var(--spacing-md);
    margin-top: var(--spacing-xl);
}

@media (max-width: 900px) {
    .about-hero-grid {
        grid-template-columns: 1fr;
        gap: var(--spacing-xl);
    }

    .resume-preview object {
        height: 620px;
    }
}

@media (max-width: 640px) {
    .about-hero {
        padding: var(--spacing-2xl) 0;
    }

    .resume-preview object {
        height: 520px;
    }

    .features-list {
        grid-template-columns: 1fr;
    }
    
    .contact-links {
        flex-direction: column;
        align-items: stretch;
    }

    .contact-links a {
        justify-content: center;
    }
}
</style>

<script>
document.addEventListener('DOMContentLoaded', function () {
    const toggle = document.getElementById('experience-toggle');
    const extraExperiences = document.querySelectorAll('.experience-extra');

    if (!toggle || !extraExperiences.length) return;

    toggle.addEventListener('click', function () {
        const expanded = toggle.getAttribute('aria-expanded') === 'true';
        const nextExpanded = !expanded;

        extraExperiences.forEach(function (card) {
            card.classList.toggle('is-hidden', !nextExpanded);
        });

        toggle.setAttribute('aria-expanded', String(nextExpanded));
        toggle.querySelector('span').textContent = nextExpanded ? 'Show Less' : 'Show More';
        toggle.querySelector('i').className = nextExpanded
            ? 'fas fa-chevron-up'
            : 'fas fa-chevron-down';
    });
});
</script>
